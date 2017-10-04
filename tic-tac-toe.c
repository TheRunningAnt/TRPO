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

void print_matrix()
{
    int t;

    for(t = 0; t < 3; t++)
    {
        print(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);

        if(t != 2)
        {
            printf("\n-|-|-\n");
        }
    }
    
    printf("\n");
}

char win_check()
{
    int t;
    char *p;

    for(t = 0; t < 3; t++) //проверка строк
    {
        p = &matrix[t][0];
        
        if(*p == *(p+1) && *(p+1) == *(p+2))
        {
            return *p;
        }
    }

    for(t = 0; t < 3; t++) //проверка столбцов
    {
        p = &matrix[0][t];

        if(*p == *(p+3) && *(p+3) == *(p+6))
        {
            return *p;
        }
    }
    
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) //проверка диагоналей
    {
        return matrix[0][0];
    }

    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        return matrix[0][2];
    }

    return SPACE;
}