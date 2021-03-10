CC = clang
TARGET = one_per_line
CFLAGS = -std=c99 -Wall -g
OBJ = one_per_line.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
