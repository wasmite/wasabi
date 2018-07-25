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
RLS_CFLAGS ?= $(COMMON_FLAGS) -DNDEBUG -ansi -pedantic
ifeq ($(CC), clang)
  RLS_CFLAGS += --analyze
endif

rwildcard=$(wildcard $1$2) \
	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CMD_FILES = $(call rwildcard,cmd/,*.c)
SRC_FILES = $(call rwildcard,src/,*.c)
TST_FILES = $(call rwildcard,tests/,*.c)

BUILD_DIR = build

all : fmt cmain tidycheck cppcheck unit
.PHONY: all

fmt:
	@ clang-format -i -style=file -fallback-style=none \
		$(call rwildcard,include/,*.h) $(SRC_FILES)
.PHONY: fmt

tidycheck:
	@ clang-tidy -header-filter=.* -system-headers --quiet \
		-checks='-*,bugprone-*,cert-*,clang-analyzer-*,-clang-analyzer-cplusplus*,performance-*,portability-*,readability-*' \
		$(SRC_FILES) -- --std=c99 -I./include
.PHONY: tidycheck

cppcheck:
	@ cppcheck --cppcheck-build-dir=$(BUILD_DIR) --enable=all --quiet \
		--std=c99 -I ./include src
.PHONY: cppcheck

run: cmain
	@ $(BUILD_DIR)/uevm
.PHONY: run

unit: cunit
	@ $(BUILD_DIR)/uevm_unit
.PHONY: unit

func: cfunc
	@ $(BUILD_DIR)/uevm_func
.PHONY: func

cmain: __bdir
	@ $(CC) $(RLS_CFLAGS) -DNUNIT -I./include -o $(BUILD_DIR)/uevm $(CMD_FILES) $(SRC_FILES)
.PHONY: cbuild

cunit: __bdir
	@ $(CC) $(DBG_CFLAGS) -I./include -o $(BUILD_DIR)/uevm_unit $(SRC_FILES)
.PHONY: cunit

cfunc: __bdir
	@ $(CC) $(DBG_CFLAGS) -DNUNIT -I./include -o $(BUILD_DIR)/uevm_func $(SRC_FILES) $(TST_FILES)
.PHONY: cfunc

clean:
	@ rm -rf $(BUILD_DIR)
.PHONY: clean

__bdir:
	@ mkdir -p $(BUILD_DIR)
.PHONY: __bdir
