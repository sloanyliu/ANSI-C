CC = clang
TARGET = histogram
CFLAGS = -std=c99 -Wall -g
OBJ = histogram.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
