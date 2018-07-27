/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  math.h
 * @brief Math util functions.
 */

#ifndef INTERNAL_MATH_H
#define INTERNAL_MATH_H

#include "uevm/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BIGINT_BYTES_SIZE 32

/*
 * @brief
 *
 */
typedef struct BigInt {
  uint8_t value[BIGINT_BYTES_SIZE];
} BigInt;

static const BigInt BIGINT_ZERO = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

static const BigInt BIGINT_MAX = {
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}};

/*
 * @brief Create new BigInt from provided array
 *
 * @param[in] value   init array
 * @param[in] len     length of init array
 *
 * @returns a new BigInt
 */
BigInt *set(BigInt *n, uint8_t *value, size_t len);

/*
 * @brief Helper function that adds two unsigned 8-bits numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a sum of two given numbers
 */
BigInt math_add(BigInt a, BigInt b);

/*
 * @brief Helper function that substract two unsigned 8-bits numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a difference of two given numbers
 */
BigInt math_sub(BigInt a, BigInt b);

/*
 * @brief Helper function that  compare 2 BigInt values
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns true if same value, false if different
 */
bool math_cmp(BigInt a, BigInt b);

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
void BigInt_print(BigInt src);

int test_new(void);

int test_cmp(void);

int test_add_lower(void);

int test_add_upper(void);

int math_testsuit(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_MATH_H */
