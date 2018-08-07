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

bool set(BigUint *n, uint8_t *value, size_t len) {
  size_t i;

  if (len > BIGUINT_BYTES_SIZE) {
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

  for (i = 0; i < BIGUINT_BYTES_SIZE; i++) {
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
    for (i = 0; i < BIGUINT_BYTES_SIZE; i++) {
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
  BigUint res;
  uint8_t v[] = {0x00};

  set(&res, v, 1);

  return res;
}

int math_cmp(BigUint a, BigUint b) {
  int i = BIGUINT_BYTES_SIZE - 1;
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

#ifndef NUNIT
#include <stdio.h>
#include "internal/test.h"

void BigUint_print(BigUint src) {
  int i = 0;
  char str[BIGUINT_BYTES_SIZE * 2];
  char *s = str;

  for (i = BIGUINT_BYTES_SIZE - 1; i >= 0; i--) {
    sprintf(s, "%02X", (int) src.abs[i]);
    s += 2;
  }
  printf("0x%s\n", str);
}

int test_new(void) {
  BigUint a;
  uint8_t v[] = {0x00, 0x01};

  set(&a, v, 2);
  ASSERT(sizeof(a.abs) == BIGUINT_BYTES_SIZE);
  ASSERT(a.abs[0] == 0x00);
  ASSERT(a.abs[1] == 0x01);
  ASSERT(a.abs[BIGUINT_BYTES_SIZE - 1] == 0x00);

  return 0;
}

int test_cmp(void) {
  BigUint a, b;
  a = b = BIGUINT_ZERO;
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
  a = b = c = res = BIGUINT_ZERO;
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
  a = b = res = BIGUINT_ZERO;
  uint8_t v1[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  uint8_t v2[] = {0x01};

  set(&a, v1, 32);
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
  a = b = BIGUINT_ZERO;
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
  return 0;
}

int test_mod(void) {
  return 0;
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
  return 0;
}
#endif
