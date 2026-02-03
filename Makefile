CC = gcc
CFLAGS = -Wall -Iinc
TARGET = snake_game
SRC = src/main.c src/snake.c
OBJ = main.o snake.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: src/main.c inc/snake.h
	$(CC) $(CFLAGS) -c src/main.c

snake.o: src/snake.c inc/snake.h
	$(CC) $(CFLAGS) -c src/snake.c

clean:
	rm -f *.o $(TARGET)
