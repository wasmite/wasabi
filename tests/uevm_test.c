/*
 * This is free and unencumbered software released into the public domain.
 * For more information, please refer to <http://unlicense.org/>
 */

/**
 * @file  uevm_test.c
 * @brief μEVM functional tests
 */

#include <stdio.h>
#include <string.h>
#include <uevm/api.h>
#include "frozen.h"

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

// This function is called by json_scanf() call above.
// str is "[1, 2]", user_data is my_data.
static void scan_array(const char *str, int len, void *user_data) {
  struct json_token t;
  int i;
  printf("Parsing array: %.*s\n", len, str);
  for (i = 0; json_scanf_array_elem(str, len, "", i, &t) > 0; i++) {
    printf("Index %d, token [%.*s]\n", i, t.len, t.ptr);
  }
}

int main(void) {
  int a, b;
  char *c;
  void *my_data = NULL;
  char str[] = "{ \"a\": 123, \"d\": true, \"b\": [1, 2], \"c\": \"hi\" }";

  json_scanf(str, strlen(str), "{ a:%d, b:%M, c:%Q, d:%B }", &a, scan_array,
             my_data, &c, &b);

  ASSERT(uevm_add(0, 0) == 0);
  printf("Tests completed succesfully\n");
  return 0;
}
