
/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file    test.h
 * @brief   Unit tests releated macros
 */

#ifndef INTERNAL_TEST_H_
#define INTERNAL_TEST_H_

#define FAIL(str, line)                             \
  do {                                              \
    printf("Fail on line %d: [%s]\n", line, str);   \
  } while (0)

#define ASSERT(expr)                                \
  do {                                              \
    if (!(expr)) FAIL(#expr, __LINE__);             \
  } while (0)

#endif /* INTERNAL_TEST_H_ */
