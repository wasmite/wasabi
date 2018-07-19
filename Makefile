COMMON_CFLAGS = -Wall -Wextra -Werror
COMMON_CFLAGS += -Wmissing-declarations
COMMON_CFLAGS += -Wmissing-prototypes
COMMON_CFLAGS += -Wstrict-prototypes

CC ?= clang
SRC_CFLAGS ?= ${COMMON_FLAGS} -g -ansi -pedantic
TST_CFLAGS ?= ${COMMON_FLAGS} -g -std=c99

PRG_FILES = main
SRC_FILES = main.c
TST_FILES = simple_test.c

all:
	${CC} ${SRC_CFLAGS} -I./include ${SRC_FILES} -o ${PRG_FILES}

fmt:
	find . -iname *.h -o -iname *.c \
	| xargs clang-format -style=file -i 

