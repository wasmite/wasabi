/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http:*unlicense.org/>
 */

/**
 * @file  math.c
 * @brief Math util functions.
 */

#include "internal/math_big_uint.h"
#include <stdio.h>

static int _get_bit(BigUint *a, uint8_t pos) {
  int res;
  uint8_t word = pos / WORD_SIZE;
  uint8_t bits = pos % WORD_SIZE;

  if (bits == 0) {
    res = a->abs[word] | 0x80;
  } else {
    uint8_t mask = 1 << bits;
    res = a->abs[word + 1] & mask;
  }

  return res;
}

static void _set_bit(BigUint *a, uint8_t pos) {
  uint8_t word = pos / WORD_SIZE;
  uint8_t bits = pos % WORD_SIZE;

  if (bits == 0) {
    a->abs[word] = a->abs[word] | 0x80;
  } else {
    uint8_t mask = 1 << bits;
    a->abs[word + 1] = a->abs[word + 1] | mask;
  }
}

static void _unset_bit(BigUint *a, uint8_t pos) {
  uint8_t word = pos / WORD_SIZE;
  uint8_t bits = pos % WORD_SIZE;

  if (bits == 0) {
    a->abs[word] = a->abs[word] | 0x7F;
  } else {
    uint8_t mask = 0xFF << bits;
    a->abs[word + 1] = a->abs[word + 1] & mask;
  }
}

BigUint new() {
  return BIGUINT_ZERO;
}

bool set(BigUint *n, uint8_t *value, size_t len) {
  size_t i;

  if (len > BIGUINT_WORDS_SIZE) {
    return FALSE;
  }

  for (i = 0; i < len; i++) {
    n->abs[i] = value[i];
  }

  return TRUE;
}

BigUint math_add(BigUint a, BigUint b) {
  BigUint res;
  uint16_t accum = 0;
  uint8_t i;

  for (i = 0; i < BIGUINT_WORDS_SIZE; i++) {
    accum = accum + a.abs[i] + b.abs[i];
    res.abs[i] = accum & 0xff;
    accum = accum >> 8;
  }

  return res;
}

BigUint math_sub(BigUint a, BigUint b) {
  BigUint res, tmp;
  int16_t accum = 0;
  uint8_t i;

  if (math_cmp(a, b) == -1) {
    /* TODO: use modulo operation to handle underflow properly */
    tmp = math_sub(b, a);
    res = math_add(math_sub(BIGUINT_MAX, tmp), BIGUINT_ONE);
  } else {
    for (i = 0; i < BIGUINT_WORDS_SIZE; i++) {
      accum = a.abs[i] - b.abs[i] - accum;
      res.abs[i] = accum & 0xff;
      accum = accum >> 8;
    }
  }

  return res;
}

BigUint math_mul(BigUint a, BigUint b) {
  return BIGUINT_ZERO;
}

BigUint math_div(BigUint a, BigUint b) {
  /* if D = 0 then error(DivisionByZeroException) end
    Q := 0                  -- Initialize quotient and remainder to zero
    R := 0
    for i := n − 1 .. 0 do  -- Where n is number of bits in N
      R := R << 1           -- Left-shift R by 1 bit
      R(0) := N(i)          -- Set the least-significant bit of R equal to bit i
  of the numerator if R ≥ D then R := R − D Q(i) := 1 end end
 */

  BigUint quot, rem, lsb;
  BigUint lsb_mask = BIGUINT_MAX;
  quot = rem = new ();

  math_lshift(&lsb_mask, 1);

  int i;
  for (i = BIGUINT_WORDS_SIZE - 1; i > 0; i--) {
    math_lshift(&rem, 1);
    lsb = math_and(a, lsb_mask);
    rem = math_or(rem, lsb);
    if (math_cmp(rem, b) >= 0) {
      rem = math_sub(rem, b);
      _set_bit(&quot, i);
    }
  }

  return quot;
}

int math_cmp(BigUint a, BigUint b) {
  int i = BIGUINT_WORDS_SIZE - 1;
  while (i > 0 && a.abs[i] == b.abs[i]) {
    i--;
  }

  if (a.abs[i] < b.abs[i]) {
    return -1;
  } else if (a.abs[i] > b.abs[i]) {
    return 1;
  }

  return 0;
}

int math_lshift(BigUint *a, uint8_t shift_size) {
  int i;
  for (i = BIGUINT_WORDS_SIZE - shift_size; i > 0; --i) {
    a->abs[i] = (a->abs[i] << 1) | (a->abs[i - 1] >> 7);
  }
  a->abs[0] <<= 1;

  return 0;
}

int math_rshift(BigUint *a, uint8_t shift_size) {
  int i;
  for (i = 0; i < BIGUINT_WORDS_SIZE - shift_size; ++i) {
    a->abs[i] = (a->abs[i] >> 1) | (a->abs[i + 1] << 7);
  }
  a->abs[BIGUINT_WORDS_SIZE - 1] >>= 1;

  return 0;
}

BigUint math_and(BigUint a, BigUint b) {
  BigUint res = new ();

  int i;
  for (i = 0; i < BIGUINT_WORDS_SIZE; i++) {
    res.abs[i] = (a.abs[i] & b.abs[i]);
  }

  return res;
}

BigUint math_or(BigUint a, BigUint b) {
  BigUint res = new ();

  int i;
  for (i = 0; i < BIGUINT_WORDS_SIZE; i++) {
    res.abs[i] = (a.abs[i] | b.abs[i]);
  }

  return res;
}

#ifndef NUNIT
#include <stdio.h>
#include "internal/test.h"

void BigUint_print(BigUint src) {
  int i = 0;
  char str[BIGUINT_WORDS_SIZE * 2];
  char *s = str;

  for (i = BIGUINT_WORDS_SIZE - 1; i >= 0; i--) {
    sprintf(s, "%02X", (int) src.abs[i]);
    s += 2;
  }
  printf("0x%s\n", str);
}

int test_new(void) {
  BigUint a;
  uint8_t v[] = {0x00, 0x01};

  set(&a, v, 2);
  ASSERT(sizeof(a.abs) == BIGUINT_WORDS_SIZE);
  ASSERT(a.abs[0] == 0x00);
  ASSERT(a.abs[1] == 0x01);
  ASSERT(a.abs[BIGUINT_WORDS_SIZE - 1] == 0x00);

  return 0;
}

int test_cmp(void) {
  BigUint a, b;
  a = b = new ();
  ASSERT(math_cmp(a, b) == 0);

  uint8_t v1[] = {0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  uint8_t v2[] = {0xff, 0xff};
  set(&a, v1, 32);
  set(&b, v2, 2);
  ASSERT(math_cmp(a, b) == 1);
  ASSERT(math_cmp(b, a) == -1);
  ASSERT(math_cmp(a, a) == 0);
  ASSERT(math_cmp(a, BIGUINT_MAX) == -1);
  /* BigUint_print(b); */
  ASSERT(math_cmp(b, b) == 0);

  return 0;
}

int test_add(void) {
  BigUint a, b, c, res;
  a = b = c = res = new ();
  uint8_t v1[] = {0xff, 0xff};
  uint8_t v2[] = {0xff, 0xff};
  uint8_t v3[] = {0xfe, 0xff, 0x01};

  set(&a, v1, 2);
  set(&b, v2, 2);
  set(&c, v3, 3);
  res = math_add(a, b);
  /* BigUint_print(res); */

  ASSERT(math_cmp(res, c) == 0);

  return 0;
}

int test_add_overflow(void) {
  BigUint a, b, res;
  a = b = res = new ();
  b = BIGUINT_MAX;
  uint8_t v2[] = {0x01};

  set(&b, v2, 1);
  res = math_add(a, b);

  /* BigUint_print(res); */
  ASSERT(math_cmp(res, BIGUINT_ZERO) == 0);

  return 0;
}

int test_sub(void) {
  BigUint a, b, res;
  a = b = res = BIGUINT_ZERO;
  uint8_t v1[] = {0x01};
  uint8_t v2[] = {0x02};

  set(&a, v1, 1);
  set(&b, v2, 1);
  res = math_add(a, a);

  /* BigUint_print(res); */
  ASSERT(math_cmp(res, b) == 0);

  return 0;
}

int test_sub_underflow(void) {
  BigUint a, b;
  a = b = new ();
  uint8_t v2[] = {0x01};

  set(&b, v2, 1);

  /* BigUint_print(math_sub(a, b)); */
  ASSERT(math_cmp(BIGUINT_MAX, math_sub(a, b)) == 0);

  return 0;
}

int test_mul(void) {
  return 0;
}

int test_div(void) {
  BigUint a, b, res;
  a = b = res = new ();
  uint8_t v1[] = {0x01};
  uint8_t v2[] = {0x02};

  set(&a, v1, 1);
  set(&b, v2, 1);
  res = math_add(a, a);

  /* BigUint_print(res); */
  ASSERT(math_cmp(res, b) == 0);

  return 0;
}

int test_mod(void) {
  return 1;
}

int test_lshift(void) {
  return 1;
}

int test_rshift(void) {
  return 1;
}

int test_and(void) {
  return 1;
}

int test_or(void) {
  return 1;
}

int math_testsuit(void) {
  TESTCASE(test_new);
  TESTCASE(test_cmp);
  TESTCASE(test_add);
  TESTCASE(test_add_overflow);
  TESTCASE(test_sub);
  TESTCASE(test_sub_underflow);
  TESTCASE(test_mul);
  TESTCASE(test_div);
  TESTCASE(test_mod);
  TESTCASE(test_lshift);
  TESTCASE(test_rshift);
  TESTCASE(test_and);
  TESTCASE(test_or);
  return 0;
}
#endif
