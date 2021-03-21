# VARIABLE INITIALIZATION
CC = gcc
TARGET = nush
FILES = src/main.c src/source.c src/scanner.c src/parser.c src/node.c src/executor.c src/prompt.c

compile:
	$(CC) $(FILES) -o $(TARGET)

clean:
	rm $(TARGET)