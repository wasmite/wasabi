#include <stdio.h>

#ifdef UEVM_TEST_ABORT_ON_FAIL
#define UEVM_TEST_ABORT abort()
#else
#define UEVM_TEST_ABORT
#endif

#define FAIL(str, line)                                              \
  do {                                                               \
    printf("%s:%d:1 [%s] (in %s)\n", __FILE__, line, str, __func__); \
    UEVM_TEST_ABORT;                                                 \
  } while (0)

#define ASSERT(expr)                    \
  do {                                  \
    if (!(expr)) FAIL(#expr, __LINE__); \
  } while (0)                           
