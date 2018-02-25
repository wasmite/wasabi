//
// Created by k2 on 2/16/18.
//
#include <stdint.h>
#include <stdio.h>
#include <gmp.h>

typedef struct WORD { uint8_t x[256]; } WORD;

typedef struct {
    WORD stack[1024];
} State;

typedef uint8_t OpCode;

OpCode getOp(uint8_t *code, uint64_t pc) {

}

void run(uint8_t *code, State *state) {
    WORD mem[1024];
    uint64_t pc = 0;

    while(1) {
        getOp(code, pc);
        state->stack;

        pc++;
    }
}

int main(int argc, char *argv[]) {
    State state;
    uint8_t code[] = {0x60, 0x05, 0x60, 0x04, 0x01};

    mpz_t n;
    mpz_init(n);
    mpz_set_ui(n, 123);
    gmp_printf ("% Zd \n", n);
    mpz_clear(n);

//    run(code, &state);

    return 0;
}