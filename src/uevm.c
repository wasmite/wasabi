/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file
 * Math util functions.
 */

#include "./math.h"

#include <brotli/types.h>

uint8_t uevm_add(uint8_t a, uint8_t b) {
  return math_add(a, b);
}
