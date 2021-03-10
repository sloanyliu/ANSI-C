CC = clang
TARGET = longest
CFLAGS = -std=c99 -Wall -g
OBJ = longest.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
