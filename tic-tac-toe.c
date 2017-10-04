#include "tic-tac-toe.h"
#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '

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