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
RLS_CFLAGS += --analyze
endif

rwildcard=$(wildcard $1$2) \
	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SRC_FILES = $(call rwildcard,src/,*.c)
TST_FILES = $(call rwildcard,tests/,*.c)

BUILD_DIR = build

all : fmt check unit build
.PHONY: all

fmt:
	@ clang-format -i -style=file -fallback-style=none \
		$(call rwildcard,include/,*.h) \
		$(call rwildcard,src/,*.h) \
		$(SRC_FILES)
.PHONY: fmt

check:
	@ clang-tidy -header-filter=.* -system-headers --quiet \
		-checks='-*,bugprone-*,cert-*,clang-analyzer-*,-clang-analyzer-cplusplus*,performance-*,portability-*,readability-*' \
		$(SRC_FILES) -- --std=c99 -I./include
	@ cppcheck --cppcheck-build-dir=$(BUILD_DIR) --enable=all --quiet \
		--std=c99 -I ./include src
.PHONY: check

build: __mkdir
	@ $(CC) $(RLS_CFLAGS) -I./include $(SRC_FILES)
.PHONY: build

unit: __mkdir
	@ $(CC) $(DBG_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_unit $(SRC_FILES)
	@ $(BUILD_DIR)/uevm_unit
.PHONY: unit

func: __mkdir
	@ $(CC) $(DBG_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_func $(TST_FILES)
	@ $(BUILD_DIR)/uevm_func
.PHONY: func

clean:
	@ rm -rf $(BUILD_DIR)
.PHONY: clean

__mkdir:
	@ mkdir -p $(BUILD_DIR)
.PHONY: __mkdir
