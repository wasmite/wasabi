# μEVM (Micro Ethereum Virtual Machine)

Highly-portable Ethereum VM distributed as a single header file
with no dependencies and licensed under public domain.

## Features

- Single header file written in C89 (ANSI C)
- Focus on portability, efficiency and simplicity
- No dependencies (not even the standard library if not wanted)

## Usage

μEVM is self contained in one single header file and can be used either
in header only mode or in implementation mode.

The header only mode is used by default and does not contain the actual
implementation, which requires to define the preprocessor macro
`UEVM_IMPLEMENTATION` before `#include`ing this file, e.g.:

```c
#define UEVM_IMPLEMENTATION
#include "uevm.h"
```

## Example

TBD

## Building

TBD

## Unlicensed

μEVM is free and unencumbered public domain software,
for more information, see http://unlicense.org/.
