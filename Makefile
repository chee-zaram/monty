CC		:= gcc
CFLAGS		:= -pedantic -std=c89
GFLAG		:= -g
RMFLAGS		:= -rf
CFILES		:= monty.c misc.c opcodes.c opcodes_2.c opcodes_arthmtcs.c \
		   stack_and_queue.c stack_list.c
CHEADERS	:= monty.h stack_list.h
TARGET		:= monty
STD_DEST	:= /bin/

install: $(CFILES) $(CHEADERS)
	$(CC) $(GFLAG) $(CFLAGS) $(CFILES) -o $(TARGET)

.PHONY: $(TARGET)
$(TARGET):
	sudo mv ./$(TARGET) $(STD_DEST)

.PHONY: clean
clean:
	rm $(RMFLAGS) $(TARGET)
