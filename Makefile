CC         := gcc
CFLAGS     := -g -Wall -Werror -Wextra -pedantic -std=c89
RM         := rm -rf
CFILES     := $(wildcard *.c)
OBJS_DIR   := objs
OBJS       := $(addprefix $(OBJS_DIR)/,$(notdir $(CFILES:%.c=%.o)))
CHEADERS   := monty.h stack_list.h
TARGET     := monty
STD_DEST   := /usr/local/bin
BIN        := $(STD_DEST)/$(TARGET)

.PHONY: install clean uninstall all

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^

${OBJS}: | ${OBJS_DIR}

${OBJS_DIR}:
	mkdir -p $@

${OBJS_DIR}/%.o: %.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c -o $@ $<

install: ${TARGET}
	sudo mv -f ${TARGET} ${STD_DEST}

clean:
	sudo ${RM} ${OBJS} ${TARGET} ${BIN}

uninstall: ${BIN}
	sudo ${RM} ${BIN}

${BIN}:
	${RM} ${TARGET}
	sudo ln -s `pwd`/${TARGET} ${BIN}
