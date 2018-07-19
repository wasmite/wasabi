/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file
 * Math util functions.
 */

#ifndef MATH_H_
#define MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <uevm/types.h>

/*
 * Helper function that adds two unsigned 8-bits numbers.
 *
 * @param[in] first number
 * @param[in] second number
 * @returns a sum of two given numbers
 */
uint8_t math_add(uint8_t a, uint8_t b);

#ifdef __cplusplus
}
#endif

#endif /* MATH_H_ */
