CC = clang
TARGET = blank_remover
CFLAGS = -std=c99 -Wall -g
OBJ = blank_remover.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
