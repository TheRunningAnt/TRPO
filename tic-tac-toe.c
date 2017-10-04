#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '

char matrix[3][3] = {
    {SPACE, SPACE, SPACE},
    {SPACE, SPACE, SPACE},
    {SPACE, SPACE, SPACE}
};

void computer_turn()
{
    register int t;
    char *p;
    p = (char*) matrix;
    
    for(t = 0; *p != SPACE && t < 9; t++)
    {
        p++;
    }

    if(t == 9)
    {
        printf("draw\n");
        exit(0);
    }
    else
    {
        *p = 'O';
    }
}

void player_turn()
{
    int x, y;

    printf("Ваш ход:\n")
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    x--;
    y--;

    if(x < 0 || y < 0 || x > 2 || y > 2 || matrix[x][y] != SPACE)
    {
        printf("Неправильный ход, попробуйте ещё раз\n");
        player_turn();
    }
    else
    {
        matrix[x][y] = 'X';
    }
}