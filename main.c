#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"

#define SPACE ' '

int main()
{
    char done;
    done = SPACE;

    printf("\n-----------------\n");
    printf("Крестики-нолики");
    printf("\n-----------------\n");

    do
    {
        print_matrix();
        player_turn();

        done = win_check();

        if(done != SPACE)
        {
            break;
        }

        computer_turn();

        done = win_check();
    } while(done == SPACE);

    if(done == 'X')
    {
        printf("Вы выиграли!\n\n");
    }
    else
    {
        printf("Вы проиграли...\n\n");
    }

    print_matrix();

    return 0;
}