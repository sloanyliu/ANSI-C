CC = clang
TARGET = in_to_out
CFLAGS = -std=c99 -Wall -g
OBJ = in_to_out.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
