#include "../inc/snake.h"

int main() {
    char board[40][40] = {0};
    Point head = {20, 20};
    run_snake(board, head);
    return 0;
}
