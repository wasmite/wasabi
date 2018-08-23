CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Wcast-align
CFLAGS += -Wpointer-arith
CFLAGS += -Wbad-function-cast
CFLAGS += -Wmissing-prototypes
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wmissing-declarations
CFLAGS += -Winline
CFLAGS += -Wundef
CFLAGS += -Wnested-externs
CFLAGS += -Wshadow
CFLAGS += -Wwrite-strings
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wfloat-equal

DST_CFLAGS ?= $(CFLAGS) -g -ansi -pedantic
DST_CFLAGS += -Wformat-nonliteral
DST_CFLAGS += -Wcast-qual

rwildcard=$(wildcard $1$2) \
	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CMD_FILES = $(call rwildcard,cmd/,*.c)
SRC_FILES = $(call rwildcard,src/,*.c)
TST_FILES = $(call rwildcard,tests/,*.c)

BLD_DIR = build

all : fmt cmain tidycheck cppcheck unit
.PHONY: all

fmt:
	@ clang-format -i -style=file -fallback-style=none \
		$(call rwildcard,include/,*.h) $(CMD_FILES) $(SRC_FILES) $(TST_FILES)
.PHONY: fmt

tidycheck:
	@ clang-tidy -header-filter=.* -system-headers --quiet \
		-checks='-*,bugprone-*,cert-*,clang-analyzer-*,-clang-analyzer-cplusplus*,performance-*,portability-*,readability-*' \
		$(CMD_FILES) $(SRC_FILES) -- --std=c99 -I./include
.PHONY: tidycheck

cppcheck:
	@ cppcheck --cppcheck-build-dir=$(BLD_DIR) --enable=all --quiet \
		--std=c99 -I ./include cmd src
.PHONY: cppcheck

run: cmain
	@ $(BLD_DIR)/uevm
.PHONY: run

unit: cunit
	@ $(BLD_DIR)/uevm_unit
.PHONY: unit

func: cfunc
	@ $(BLD_DIR)/uevm_func
.PHONY: func

cmain: __bdir
	@ $(CC) $(DST_CFLAGS) -DNUNIT -I./include -o $(BLD_DIR)/uevm $(CMD_FILES) $(SRC_FILES)
.PHONY: cmain

cunit: __bdir
	@ $(CC) $(DBG_CFLAGS) -I./include -o $(BLD_DIR)/uevm_unit $(SRC_FILES)
.PHONY: cunit

cfunc: __bdir
	@ $(CC) $(DBG_CFLAGS) -DNUNIT -I./include -o $(BLD_DIR)/uevm_func $(SRC_FILES) $(TST_FILES)
.PHONY: cfunc

clean:
	@ rm -rf $(BLD_DIR)
.PHONY: clean

__bdir:
	@ mkdir -p $(BLD_DIR)
.PHONY: __bdir
