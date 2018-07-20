/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  api.h
 * @brief μEVM public API.
 */

#ifndef UEVM_API_H
#define UEVM_API_H

#include "types.h"

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
 *
 * @api
 */
uint8_t uevm_add(uint8_t a, uint8_t b);

#ifdef __cplusplus
}
#endif

#endif /* UEVM_API_H */
