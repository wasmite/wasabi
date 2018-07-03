# μEVM (Micro Ethereum Virtual Machine)

Highly-portable Ethereum VM [complains EVMC API](https://github.com/ethereum/evmc),
distributed as a single header file without dependencies and licensed under public domain.

## Features

- Single header file written in C89 (ANSI C)
- Focus on portability, efficiency and simplicity
- No dependencies (not even the standard library if not wanted)
- Low memory footprint with total memory control if needed or wanted
- Customizable modules (you can compile and use only what you need)

## Usage

This vm is self contained in one single header file and can be used either
in header only mode or in implementation mode. The header only mode is used
by default when included and allows including this header in other headers
and does not contain the actual implementation.

The implementation mode requires to define  the preprocessor macro
`UEVM_IMPLEMENTATION` in *one* .c/.cpp file before `#include`ing this file, e.g.:

```c
#define UEVM_IMPLEMENTATION
#include "uevm.h"
```

## Example

TBD

## Building

TBD

## Unlicensed

μEVM is free and unencumbered public domain software, for more information, see http://unlicense.org/.
