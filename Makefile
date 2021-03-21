# VARIABLE INITIALIZATION
CC = gcc
TARGET = nush
FILES = src/main.c src/source.c src/scanner.c src/parser.c src/node.c src/executor.c src/prompt.c

compile:
	$(CC) $(F1) $(F2) $(F3) $(F4) $(F5) $(F6) $(F7) -o $(TARGET)

clean:
	rm $(TARGET)