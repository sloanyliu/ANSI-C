CC = clang
TARGET = hello_world
CFLAGS = -std=c99 -Wall -g
OBJ = hello_world.o hello_world

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
