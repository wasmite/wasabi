/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file
 * @brief Math util functions.
 */

#ifndef INTERNAL_MATH_H_
#define INTERNAL_MATH_H_

#include "./include/uevm/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief Helper function that adds two unsigned 8-bits numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a sum of two given numbers
 */
uint8_t math_add(uint8_t a, uint8_t b);

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_MATH_H_ */
