#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    unsigned char x;
    unsigned char y;
} Point;

void run_snake(char board[40][40], Point head);

#endif
