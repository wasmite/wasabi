
/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file    test.h
 * @brief   Unittests releated macros
 */

#ifndef INTERNAL_TEST_H_
#define INTERNAL_TEST_H_

#include <stdio.h>

#define FAIL()                                       \
  do {                                               \
    printf("Fail in '%s:%d'\n", __FILE__, __LINE__); \
    return 1;                                        \
  } while (0)

#define ASSERT(expr)                                                \
  do {                                                              \
    if (!(expr)) {                                                  \
      printf("'%s' fails in '%s:%d'\n", #expr, __FILE__, __LINE__); \
      return 1;                                                     \
    }                                                               \
  } while (0)

#define TESTCASE(case)                \
  do {                                \
    int resp;                         \
    if (resp = (case)()) return resp; \
  } while (0)

#define TESTSUIT(suit) TESTCASE(suit)

#endif /* INTERNAL_TEST_H_ */
