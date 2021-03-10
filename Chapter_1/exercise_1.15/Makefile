CC = clang
TARGET = tempFunc
CFLAGS = -std=c99 -Wall -g
OBJ = tempFunc.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
