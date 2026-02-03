#include "../inc/snake.h"

void run_snake(char board[40][40], Point head) {
    int c = 'd'; 
    int alive = 1;
    short highest_score = 0;
    short current_score = 0;

    FILE* hr = fopen("highscore.txt", "r");
    if (hr) 
    {
        fscanf(hr, "%hd", &highest_score);
        fclose(hr);
    }

    srand(time(NULL));
    Point apple = {rand() % 40, rand() % 40};
    board[apple.x][apple.y] = 2;

    int snake_size = 1;
    Point* snake = calloc(1600, sizeof(Point)); 
    snake[0] = head;
    board[head.x][head.y] = 1;

    system("stty -icanon -echo");
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK); 

    printf("\033[H\033[J");

    while(alive) 
    {
        printf("\033[1;1H");
        printf("\t\t\t\t\t\tCURRENT SCORE : %hd\n", current_score); 
        printf("\t\t\t\t\t\tHIGHEST SCORE : %hd\n", highest_score);

        int input = getchar();
        if (input != EOF) 
        {
            if ((input == 'w' || input == 'W') && (c != 's' && c != 'S')) c = input;
            else if ((input == 's' || input == 'S') && (c != 'w' && c != 'W')) c = input;
            else if ((input == 'a' || input == 'A') && (c != 'd' && c != 'D')) c = input;
            else if ((input == 'd' || input == 'D') && (c != 'a' && c != 'A')) c = input;
        }

        Point old_tail = snake[snake_size - 1];
        Point new_head = snake[0];

        if (c == 'w' || c == 'W') new_head.x--;
        else if (c == 's' || c == 'S') new_head.x++;
        else if (c == 'a' || c == 'A') new_head.y--;
        else if (c == 'd' || c == 'D') new_head.y++;

        if (new_head.x < 0 || new_head.x >= 40 || new_head.y < 0 || new_head.y >= 40 
            || (board[new_head.x][new_head.y] == 1 && !(new_head.x == old_tail.x && new_head.y == old_tail.y))) 
        {
            alive = 0;
            break;
        }

        char ate_apple = (new_head.x == apple.x && new_head.y == apple.y);

        for (int i = snake_size - 1; i > 0; i--) 
        {
            snake[i] = snake[i - 1];
        }
        snake[0] = new_head;

        if (ate_apple) 
        {
            snake_size++;
            snake[snake_size - 1] = old_tail; 
            current_score++;
            if (current_score > highest_score) 
            {
                highest_score = current_score;
                FILE* hw = fopen("highscore.txt", "w");
                if (hw) 
                    { 
                        fprintf(hw, "%hd", highest_score); fclose(hw); 
                    }
            }
            do 
            {
                apple.x = rand() % 40;
                apple.y = rand() % 40;
            }
            while (board[apple.x][apple.y] != 0);
            board[apple.x][apple.y] = 2;
        }
        else 
        {
            board[old_tail.x][old_tail.y] = 0;
        }

        board[snake[0].x][snake[0].y] = 1;

        printf("\033[4;1H");
        for (int i = 0; i < 40; i++) 
        {
            printf("\t\t\t\t\t\t"); 
            for (int j = 0; j < 40; j++) 
            {
                printf("%s",board[i][j] & 1 ? "🟩" : board[i][j] & 2 ? "🟥" : (i + j) & 1 ? "⬛" : "🟫");
            }
            printf("\n");
        }
        fflush(stdout);
        usleep(200000); 
    }

    printf("\033[H\033[J"); 
    printf("\n\n\t\t\t\t\t\tGAME OVER\n");
    printf("\t\t\t\t\t\tSCORE: %hd\n", current_score);
    
    free(snake);
    system("stty icanon echo");
}
