COMMON_FLAGS = -Wall -Wextra -Werror
COMMON_FLAGS += -Wformat-nonliteral
COMMON_FLAGS += -Wcast-align
COMMON_FLAGS += -Wpointer-arith
COMMON_FLAGS += -Wbad-function-cast
COMMON_FLAGS += -Wmissing-prototypes
COMMON_FLAGS += -Wstrict-prototypes
COMMON_FLAGS += -Wmissing-declarations
COMMON_FLAGS += -Winline
COMMON_FLAGS += -Wundef
COMMON_FLAGS += -Wnested-externs
COMMON_FLAGS += -Wcast-qual
COMMON_FLAGS += -Wshadow
COMMON_FLAGS += -Wwrite-strings
COMMON_FLAGS += -Wno-unused-parameter
COMMON_FLAGS += -Wfloat-equal

DBG_CFLAGS ?= $(COMMON_FLAGS) -g -std=c99
RLS_CFLAGS ?= $(COMMON_FLAGS) -DNDEBUG -c -ansi -pedantic

ifeq ($(CC),clang)
SRC_CFLAGS += --analyze
endif

SRC_FILES = ./src/core/math.c ./src/uevm.c
TST_FILES = ./tests/uevm_test.c

BUILD_DIR = build

all : fmt check unit build
.PHONY: all

fmt:
	find . -iname *.h -o -iname *.c \
		| xargs clang-format -style=file -i -fallback-style=none
.PHONY: fmt

check:
	find . -iname *.h -o -iname *.c \
		| xargs clang-tidy -checks='*'
	find . -iname *.h -o -iname *.c \
		| xargs cppcheck --enable=all
.PHONY: check

build: __mkdir
	$(CC) $(RLS_CFLAGS) -I./include $(SRC_FILES)
.PHONY: build

unit: __mkdir
	$(CC) $(DBG_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_unit $(SRC_FILES)
	$(BUILD_DIR)/uevm_unit
.PHONY: unit

func: __mkdir
	$(CC) $(DBG_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_func $(TST_FILES)
	$(BUILD_DIR)/uevm_func
.PHONY: func

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

__mkdir:
	mkdir -p $(BUILD_DIR)
.PHONY: __mkdir
