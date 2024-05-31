EXECUTABLE_NAME = main.out
SOURCE_FILE = main.c

CC = cc
CFLAGS = -Wall -pthread

ALL_FLAGS = $(CFLAGS)

all:
	$(CC) $(SOURCE_FILE) -o $(EXECUTABLE_NAME) $(ALL_FLAGS)

execute:
	./$(EXECUTABLE_NAME)