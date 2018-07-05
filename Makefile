COMMON_CFLAGS = -Wall -Wextra -Wpedantic -Werror
COMMON_CFLAGS += -Wmissing-declarations
COMMON_CFLAGS += -Wmissing-prototypes
COMMON_CFLAGS += -Wstrict-prototypes

CC ?= clang
SRC_CFLAGS ?= ${COMMON_FLAGS} -g -std=c89
TST_CFLAGS ?= ${COMMON_FLAGS} -g -std=c99

PRG_FILES = main
SRC_FILES = main.c
TST_FILES = simple_test.c

all:
	${CC} ${SRC_CFLAGS} src/${SRC_FILES} -o ${PRG_FILES}
