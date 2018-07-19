#include <stdio.h>
#include "uevm/api.h"

#define FAIL(str, line)                           \
  do {                                            \
    printf("Fail on line %d: '%s'\n", line, str); \
  } while (0)

#define ASSERT(expr)                    \
  do {                                  \
    if (!(expr)) FAIL(#expr, __LINE__); \
  } while (0)

int main() {
  ASSERT(uevm_add(0, 0) == 0);
  ASSERT(uevm_add(0, 1) == 1);
  ASSERT(uevm_add(1, 0) == 1);
  ASSERT(uevm_add(1, 1) == 2);
  printf("Tests completed\n");
  return 0;
}
