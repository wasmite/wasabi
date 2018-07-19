/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file    uevm.c
 * @brief   μEVM public API impl.
 */

#include "internal/math.h"

#include "uevm/types.h"

uint8_t uevm_add(uint8_t a, uint8_t b) {
  return math_add(a, b);
}

int main() {
  return 0;
}
