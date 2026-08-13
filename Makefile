# Compiler & Flags
CC ?= gcc
CFLAGS ?= -Wall -Wextra -O2

C_GOALS := $(filter %.c,$(MAKECMDGOALS))

.PHONY: all clean run $(C_GOALS)

# Default target when running plain 'make'
all: app

# Rule 1: Typing 'make file.c' compiles file.c -> executable 'file'
ifneq ($(C_GOALS),)
$(C_GOALS):
	$(CC) $(CFLAGS) $@ -o $(basename $@)
endif

# Rule 2: Typing 'make file' compiles file.c -> executable 'file'
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Helper command to build and run: make run FILE=test.c
FILE ?= main.c
TARGET := $(basename $(FILE))
run: $(TARGET)
	./$(TARGET)

# Clean built executables
clean:
	rm -f *.o *.exe app

