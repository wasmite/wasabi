COMMON_FLAGS = -Wall -Wextra -Werror
COMMON_FLAGS += -Wmissing-declarations
COMMON_FLAGS += -Wmissing-prototypes
COMMON_FLAGS += -Wstrict-prototypes

SRC_CFLAGS ?= $(COMMON_FLAGS) -DNDEBUG -c -ansi -pedantic
TST_CFLAGS ?= $(COMMON_FLAGS) -g -std=c99

ifeq ($(CC),clang)
SRC_CFLAGS += --analyze
endif

SRC_FILES = ./src/core/math.c ./src/uevm.c
TST_FILES = ./tests/uevm_test.c

BUILD_DIR = build

all : fmt check build unit
	$(BUILD_DIR)/uevm_unit
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
	## TODO: build into a single C-file named "uevm.c"
	$(CC) $(SRC_CFLAGS) -I./include $(SRC_FILES)
.PHONY: build

unit: __mkdir
	$(CC) $(TST_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_unit $(SRC_FILES)
.PHONY: unit

func: __mkdir
	$(CC) $(TST_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_func $(TST_FILES)
.PHONY: func

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

__mkdir:
	mkdir -p $(BUILD_DIR)
.PHONY: __mkdir
