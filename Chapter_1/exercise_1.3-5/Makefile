CC = clang
TARGET = temperature
CFLAGS = -std=c99 -Wall -g
OBJ = temperature.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ)
