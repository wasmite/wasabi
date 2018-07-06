MEVM= .

include $(MEVM)/config

all:
	${CC} ${SRC_CFLAGS} src/${SRC_FILES} -o ${PRG_FILES}
