/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  types.h
 * @brief Common type definitions.
 */

#ifndef UEVM_TYPES_H
#define UEVM_TYPES_H

#include <stddef.h> /* for size_t */

#if defined(_MSC_VER) && (_MSC_VER < 1600)
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
typedef __int64 int64_t;
#else
#include <stdint.h>
#endif /* defined(_MSC_VER) && (_MSC_VER < 1600) */

#endif /* UEVM_TYPES_H */
