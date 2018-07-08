MEVM= .

include $(MEVM)/config

all:
	${CC} ${SRC_CFLAGS} -I./include ${SRC_FILES} -o ${PRG_FILES}

tests:
	go run tests/VMTester.go test