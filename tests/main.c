#include <stdio.h>

#include "uevm.h"


int main()
{
    uint8_t test_code[5] = {0x60, 0x05, 0x60, 0x04, 0x01};
    size_t code_len = sizeof(test_code) / sizeof(test_code[0]);
    
    EVM evm = NewEVM();
    printf("Created new EVM\n");

    Run(&evm, test_code, code_len);
    printf("Finished\n");

    return 0;
}
