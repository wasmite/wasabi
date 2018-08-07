/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  math.h
 * @brief Math util functions.
 */

#ifndef INTERNAL_BIGINT_H
#define INTERNAL_BIGINT_H

#include "internal/math_big_uint.h"
#include "uevm/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief
 *
 */
typedef struct BigInt {
  BigUint abs; /* absolute value of signed integer */
  int sign;    /* sign of integer */
} BigInt;

/*
 * @brief Create new BigInt from provided array
 *
 * @param[in] value   init array
 * @param[in] len     length of init array
 *
 * @returns a new BigInt
 */
bool set(BigInt *n, uint8_t *value, size_t len);

/*
 * @brief Helper function that adds two BigInt numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a sum of two given numbers
 */
BigInt add(BigInt a, BigInt b);

/*
 * @brief Helper function that substract two BigInt numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a difference of two given numbers
 */
BigInt sub(BigInt a, BigInt b);

/*
 * @brief Helper function that divides two BigInt numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a division of two given numbers
 */
BigInt div(BigInt a, BigInt b);

/*
 * @brief Helper function that  compare 2 BigInt values
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns true if same value, false if different
 */
bool cmp(BigInt a, BigInt b);

/*
 * @brief Helper function that sign of BigInt value
 *
 * @param[in] a     BigInt value to check sign
 *
 * @returns true if same value, false if different
 */
int sign(BigInt a);

/*
 * @brief Create new BigInt from provided string
 *
 * @param[in] str     string of value
 * @param[in] len     length of string
 *
 * @returns a new BigInt
 */
/* BigInt FromStr(char *str, size_t len); */

#ifndef NUNIT

int test_new(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_BigInt_H */
