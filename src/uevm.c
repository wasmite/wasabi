/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  uevm.c
 * @brief μEVM public API impl.
 */

#include "internal/math.h"
#include "uevm/api.h"

uint8_t uevm_add(uint8_t a, uint8_t b) {
  return math_add(a, b);
}

#ifndef NUNIT
#include "internal/test.h"

static int test_add(void) {
  ASSERT(uevm_add(0, 0) == 0);
  ASSERT(uevm_add(0, 1) == 1);
  ASSERT(uevm_add(1, 0) == 1);
  ASSERT(uevm_add(1, 1) == 2);
  return 0;
}

static int testsuit(void) {
  TESTCASE(test_add);
  return 0;
}

int main(void) {
  TESTSUIT(math_testsuit);
  TESTCASE(testsuit);
  return 0;
}
#endif
