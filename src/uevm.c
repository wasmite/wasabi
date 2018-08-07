/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  uevm.c
 * @brief μEVM public API impl.
 */

#include "internal/math_big_uint.h"
#include "uevm/api.h"

uint8_t uevm_add(uint8_t a, uint8_t b) {
  return 0;
}

#ifndef NUNIT
#include "internal/test.h"

int main(void) {
  TESTSUIT(math_testsuit);
  return 0;
}
#endif
