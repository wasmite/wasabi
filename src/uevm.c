#include "uevm.h"

static Stack NewStack() {
    Stack st;
    return st;
}

static Interpreter NewInterpreter() {
    Interpreter it;
    return it;
}

EVM NewEVM() {
    EVM e;
    e.stack = NewStack();
    e.interpreter = NewInterpreter();
   
    return e;
}