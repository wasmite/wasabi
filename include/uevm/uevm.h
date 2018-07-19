/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file
 * μEVM public API.
 */

#ifndef UEVM_H_
#define UEVM_H_

#ifdef __cplusplus
extern "C" {
#endif

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

#define EVM_WORD_SIZE 32
#define EVM_STACK_SIZE 1024

typedef uint8_t Word;

typedef enum { STOP = 0x00, ADD = 0x01, LT = 0x10, PUSH1 = 0x60 } OpCode;

typedef struct {
  uint8_t data[EVM_STACK_SIZE];
  int top;
} Stack;

typedef struct {
  Stack stack;
  uint16_t pc;
} EVM;

/*
 * Create new EVM
 */
EVM NewEVM();

#ifdef __cplusplus
}
#endif

#endif /* UEVM_H_ */
