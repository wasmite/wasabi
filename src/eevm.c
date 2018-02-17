//
// Created by k2 on 2/16/18.
//
#include <stdint>

typedef struct WORD { uint_8 x[256]; } WORD;

typedef struct {
    WORD stack[1024];
} State;