/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  math.h
 * @brief Math util functions.
 */

#ifndef INTERNAL_MATH_BIGUINT_H
#define INTERNAL_MATH_BIGUINT_H

#include "uevm/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WORD_SIZE 8
#define BIGUINT_WORDS_SIZE 32

/*
 * @brief
 *
 */
typedef struct BigUint {
  uint8_t abs[BIGUINT_WORDS_SIZE]; /* absolute value of an unsigned integer */
} BigUint;

static const BigUint BIGUINT_ZERO = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

static const BigUint BIGUINT_ONE = {
    {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

static const BigUint BIGUINT_MAX = {
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}};

/*
 * @brief Create new BigUint
 *
 * @returns a new BigUint set to 0
 */
BigUint new(void);

/*
 * @brief Set BigUint value to provided array
 *
 * @param[in] value   initialization array
 * @param[in] len     length of array
 *
 * @returns BigUint set to `value` array
 */
bool set(BigUint *n, uint8_t *value, size_t len);

/*
 * @brief Helper function that computes modulo.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a % b
 */
BigUint math_mod(BigUint a, BigUint b);

/*
 * @brief Helper function that adds two BigUint numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a sum of two given numbers
 */
BigUint math_add(BigUint a, BigUint b);

/*
 * @brief Helper function that substract two BigUint numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a difference of two given numbers
 */
BigUint math_sub(BigUint a, BigUint b);

/*
 * @brief Helper function that muliplies two BigUint numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a multiplication of two given numbers
 */
BigUint math_mul(BigUint a, BigUint b);

/*
 * @brief Helper function that divides two BigUint numbers.
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a division of two given numbers
 */
BigUint math_div(BigUint a, BigUint b);

/*
 * @brief Helper function that compare 2 BigUint values
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns:
 *	-1 if a <  b
 *	 0 if a == b
 *	+1 if a >  b
 */
int math_cmp(BigUint a, BigUint b);

/*
 * @brief Bitwise `and` of two BigUint
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a & b
 */
BigUint math_and(BigUint a, BigUint b);

/*
 * @brief Bitwise `or` of two BigUint
 *
 * @param[in] a     first number
 * @param[in] b     second number
 *
 * @returns a | b
 */
BigUint math_or(BigUint a, BigUint b);

/*
 * @brief Bitwise shift left (`<<`) of BigUint
 *
 * @param[in] a             value to be shifted
 * @param[in] shift_size    size of shift
 *
 * @returns a << shift_size
 */
int math_lshift(BigUint *a, uint8_t shift_size);

/*
* @brief Bitwise shift right (`<<`) of BigUint
*
* @param[in] a              value to be shifted
* @param[in] shift_size     size of shift
*
* @returns a >> shift_size
*/
int math_rshift(BigUint *a, uint8_t shift_size);

/*
 * @brief Create new BigUint from provided string
 *
 * @param[in] str     string of value
 * @param[in] len     length of string
 *
 * @returns a new BigUint
 */
/* BigUint FromStr(char *str, size_t len); */

#ifndef NUNIT
void BigUint_print(BigUint src);
int test_new(void);
int test_cmp(void);
int test_sub(void);
int test_sub_underflow(void);
int test_add(void);
int test_add_overflow(void);
int test_mul(void);
int test_div(void);
int test_mod(void);
int test_and(void);
int test_or(void);
int test_lshift(void);
int test_rshift(void);
int math_testsuit(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* INTERNAL_MATH_BIGUINT_H */
