# μEVM (Micro Ethereum Virtual Machine)

Highly-portable Ethereum VM with no dependencies licensed under public domain.

## Features

- Single source file written in ANSI C (C89)
- Focus on portability, efficiency and simplicity
- No dependencies (not even `libc` if not wanted)

## Building

By default, check format style, run static analyzers, unittests and build
an `μEVM` distribution:

```bash
make
```

How to build `μEVM` distribution:

```bash
make dist
```

How to check the format style:

```bash
make fmt
```

How to run static analyzers:

```bash
make check
```

How to run unit tests:

```bash
make unit
```

How to run unit tests and generate coverage reports:

```bash
make coverage
```

How to run functional tests:

```bash
make func
```

How to clean up build files:

```bash
make clean
```

## Usage

μEVM is contributed as a single file named "uevm.c" contains everything
an application needs to embed μEVM.

Check out [the documentation](docs/Readme.md) for more details.

## Q&A

TBD;

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
