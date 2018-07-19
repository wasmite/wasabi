CC ?= clang

OS := $(shell uname)

COMMON_CFLAGS = -Wall -Wextra -Werror
COMMON_CFLAGS += -Wmissing-declarations
COMMON_CFLAGS += -Wmissing-prototypes
COMMON_CFLAGS += -Wstrict-prototypes

SRC_CFLAGS ?= $(COMMON_FLAGS) -g -ansi -pedantic
TST_CFLAGS ?= $(COMMON_FLAGS) -g -std=c99

SRC_FILES = ./src/internal/math.c ./src/uevm.c
TST_FILES = ./tests/uevm_test.c

BUILD_DIR = build

all:
	mkdir -p $(BUILD_DIR)
	$(CC) $(SRC_CFLAGS) -I./include $(SRC_FILES) -o $(BUILD_DIR)/unittests

fmt: ## apply `clang-format` to all source code
	find . -iname *.h -o -iname *.c \
		| xargs clang-format -style=file -i -fallback-style=none

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean fmt check unit coverage tests
