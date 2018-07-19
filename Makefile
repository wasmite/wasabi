OS := $(shell uname)

CC ?= clang
LD ?= llvm-ld

COMMON_CFLAGS = -Wall -Wextra -Werror
COMMON_CFLAGS += -Wmissing-declarations
COMMON_CFLAGS += -Wmissing-prototypes
COMMON_CFLAGS += -Wstrict-prototypes

SRC_CFLAGS ?= $(COMMON_FLAGS) -g -ansi -pedantic
TST_CFLAGS ?= $(COMMON_FLAGS) -g -std=c99

PRG_FILES = ./build/uevm
SRC_FILES = ./src/internal/math.c ./src/uevm.c
TST_FILES = ./tests/uevm_test.c

all:
	mkdir -p build
	$(CC) $(SRC_CFLAGS) -I./include $(SRC_FILES) -o $(PRG_FILES)

fmt:
	find . -iname *.h -o -iname *.c -o \
		| xargs clang-format -style=file -i -fallback-style=none

clean:
	rm -rf build

.PHONY: all clean fmt check unit coverage tests
