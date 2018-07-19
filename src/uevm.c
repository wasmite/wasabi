/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file    uevm.c
 * @brief   μEVM public API impl.
 */

#include <stdio.h>
#include "internal/math.h"
#include "uevm/api.h"

uint8_t uevm_add(uint8_t a, uint8_t b) {
  return math_add(a, b);
}

int main() {
  printf("Hello, world!\n");
  return 0;
}
