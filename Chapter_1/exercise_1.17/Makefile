CC = clang
TARGET = plus80
CFLAGS = -std=c99 -Wall -g
OBJ = plus80.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
