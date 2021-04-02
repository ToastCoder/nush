# VARIABLE INITIALIZATION
CC = gcc
TARGET = nush
FILES = src/executor.c src/initsh.c src/main.c src/node.c src/parser.c src/prompt.c src/scanner.c src/source.c src/builtins/builtins.c src/builtins/dump.c src/symtab/symtab.c

compile:
	$(CC) $(FILES) -o $(TARGET)

clean:
	rm $(TARGET)