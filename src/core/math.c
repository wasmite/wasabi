/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  math.c
 * @brief Math util functions.
 */

#include "math.h"

uint8_t math_add(uint8_t a, uint8_t b) {
  return a + b;
}

#ifndef NDEBUG
#include "test.h"

static int test_add(void) {
  ASSERT(math_add(0, 0) == 0);
  ASSERT(math_add(0, 1) == 1);
  ASSERT(math_add(1, 0) == 1);
  ASSERT(math_add(1, 1) == 2);
  return 0;
}

int math_testsuit(void) {
  TESTCASE(test_add);
  return 0;
}
#endif
