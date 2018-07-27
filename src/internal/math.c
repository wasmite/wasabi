/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http:*unlicense.org/>
 */

/**
 * @file  math.c
 * @brief Math util functions.
 */

#include "internal/math.h"

BigInt *set(BigInt *n, uint8_t *value, size_t len) {
  size_t i;

  if (len > BIGINT_BYTES_SIZE) {
    return NULL;
  }

  for (i = 0; i < len; i++) {
    n->value[i] = value[i];
  }

  return n;
}

BigInt math_add(BigInt a, BigInt b) {
  BigInt res;
  uint16_t accum = 0;
  uint8_t i;

  for (i = 0; i < BIGINT_BYTES_SIZE; i++) {
    accum = accum + a.value[i] + b.value[i];
    res.value[i] = accum & 0xff;
    accum = accum >> 8;
  }

  return res;
}

BigInt math_sub(BigInt a, BigInt b) {
  BigInt res;
  uint8_t v[] = {0x00};

  set(&res, v, 1);

  return res;
}

bool math_cmp(BigInt a, BigInt b) {
  int i;
  for (i = 0; i < BIGINT_BYTES_SIZE; i++) {
    if (a.value[i] != b.value[i]) {
      return FALSE;
    }
  }

  return TRUE;
}

#ifndef NUNIT
#include <stdio.h>
#include "internal/test.h"

void BigInt_print(BigInt src) {
  int i = 0;
  char str[BIGINT_BYTES_SIZE * 2];
  char *s = str;

  for (i = BIGINT_BYTES_SIZE - 1; i >= 0; i--) {
    sprintf(s, "%02X", (int) src.value[i]);
    s += 2;
  }
  printf("0x%s\n", str);
}

int test_new(void) {
  BigInt a;
  uint8_t v[] = {0x00, 0x01};

  set(&a, v, 2);
  ASSERT(sizeof(a.value) == BIGINT_BYTES_SIZE);
  ASSERT(a.value[0] == 0x00);
  ASSERT(a.value[1] == 0x01);
  ASSERT(a.value[BIGINT_BYTES_SIZE - 1] == 0x00);

  return 0;
}

int test_cmp(void) {
  BigInt a, b;
  a = b = BIGINT_ZERO;
  ASSERT(math_cmp(a, b));

  uint8_t v1[] = {0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  uint8_t v2[] = {0xff, 0xff};
  set(&a, v1, 32);
  set(&b, v2, 2);
  ASSERT(!math_cmp(a, b));

  return 0;
}

int test_add_lower(void) {
  BigInt a, b, c, res;
  a = b = c = res = BIGINT_ZERO;
  uint8_t v1[] = {0xff, 0xff};
  uint8_t v2[] = {0xff, 0xff};
  uint8_t v3[] = {0xfe, 0xff, 0x01};

  set(&a, v1, 2);
  set(&b, v2, 2);
  set(&c, v3, 3);
  res = math_add(a, b);
  /* BigInt_print(res); */

  ASSERT(math_cmp(res, c));

  return 0;
}

int test_add_upper(void) {
  BigInt a, b, c, res;
  a = b = c = res = BIGINT_ZERO;
  uint8_t v1[] = {0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  uint8_t v2[] = {0x01};

  c = BIGINT_MAX;
  set(&a, v1, 32);
  set(&b, v2, 1);
  res = math_add(a, b);

  /* BigInt_print(res); */
  ASSERT(math_cmp(res, c));

  return 0;
}

int math_testsuit(void) {
  TESTCASE(test_new);
  TESTCASE(test_cmp);
  TESTCASE(test_add_lower);
  TESTCASE(test_add_upper);
  return 0;
}
#endif
