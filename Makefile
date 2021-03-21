CC = gcc
TARGET = nush
F1 = main.c
F2 = source.c
F3 = scanner.c
F4 = parser.c
F5 = node.c
F6 = executor.c
F7 = prompt.c

compile:
	$(CC) $(F1) $(F2) $(F3) $(F4) $(F5) $(F6) $(F7) -o $(TARGET)

clean:
	rm $(TARGET)