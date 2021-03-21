# VARIABLE INITIALIZATION
CC = gcc
TARGET = nush
FILES = main.c source.c scanner.c parser.c node.c executor.c prompt.c

compile:
	$(CC) $(F1) $(F2) $(F3) $(F4) $(F5) $(F6) $(F7) -o $(TARGET)

clean:
	rm $(TARGET)