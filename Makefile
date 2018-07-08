MEVM= .

include $(MEVM)/config

all:
	${CC} ${SRC_CFLAGS} -I./include ${SRC_FILES} -o ${PRG_FILES}
