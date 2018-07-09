#include <stdio.h>

#include "uevm.h"


/* Stack */
static Stack NewStack() {
    Stack st = { {0}, -1 };
    
    return st;
}
static int push(Stack * const stack, uint8_t word) {
    if (stack->top > EVM_STACK_SIZE -1) {
        return -1;
    } 
    stack->top++;
    stack->data[stack->top] = word;
    
    return 0;
}
static Word pop(Stack * const stack) {
    Word w;
   
    if (stack->top < 0) {
        return -1;
    }

    w = stack->data[stack->top];
    stack->top--;
    return w;
}
static int execute(EVM * const vm, OpCode opcode, uint8_t code[]) {
    switch(opcode) {
        case STOP: {
            break;
        }
        
        case ADD: {
            /* mpz_t out;
            * mpz_init(out);
            * mpz_fac_ui(out, 100);
            * mpz_out_str(stdout, 10, out);
            */
            Word x, y, res;
            x = pop(&vm->stack);
            y = pop(&vm->stack);
            res = x + y;
            push(&vm->stack, res);
        }

        case PUSH1: {
            uint8_t i;
            i = code[vm->pc];
            vm->pc++;
            push(&vm->stack, i);  
        }

        default: {
            break;
        }
    }
}

static void printCurrentState(EVM * const vm) {
    int i;
    printf("PC: %d\n", vm->pc);
    printf("Stack:\n");
    for (i = 0; i < EVM_STACK_SIZE; i++) {
        if (vm->stack.data[i] != 0) {
            printf("%d:\t %x\n", i, vm->stack.data[i]);
        }
    }
}

EVM NewEVM() {
    EVM e;
    e.stack = NewStack();
    e.pc = 0;
    
    return e;
}

void Run(EVM * const vm, uint8_t* code, size_t code_len) {
    OpCode op;
    while(vm->pc < code_len) {
        op = (OpCode) code[vm->pc];
        vm->pc++;
        execute(vm, op, code);
        printf("\nOpCode: %x\n", op);
        printCurrentState(vm);
    }
}
