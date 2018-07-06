# μEVM (Micro Ethereum Virtual Machine)

Highly-portable Ethereum VM distributed as a single header file
with no dependencies and licensed under public domain.

## Features

- Single header file written in C89 (ANSI C)
- Focus on portability, efficiency and simplicity
- No dependencies (not even `libc` if not wanted)

## Building

```bash
make
```

## Usage

μEVM is self contained in one single header file and can be used either
in header only mode (by default) or in implementation mode (is activated
by the preprocessor macro `UEVM_IMPLEMENTATION`), e.g.:

```c
#define UEVM_IMPLEMENTATION
#include "uevm.h"
```

## Example

```c
// TBD
```

Check out [the documentation](docs/Readme.md) for more details.

## Public Domain

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

