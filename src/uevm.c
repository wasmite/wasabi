/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file    uevm.c
 * @brief   μEVM public API impl.
 */

#include <stdio.h>
#include "core/math.h"
#include "uevm/api.h"

uint8_t uevm_add(uint8_t a, uint8_t b) {
  return math_add(a, b);
}

#ifndef NDEBUG
#include "core/test.h"

int main() {
  TESTSUIT(math_testsuit);
  return 0;
}
#endif
