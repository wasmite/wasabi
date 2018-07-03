CC = clang
CFLAGS = -Wall -Wextra -g -std=c89
SRC_FILES = main.c

all: 
	${CC} ${CFLAGS} ${SRC_FILES} -o main