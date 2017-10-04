#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"

#define SPACE ' '

int main()
{
    char done;
    done = SPACE;
    int player;

    printf("\n-----------------\n");
    printf("Крестики-нолики");
    printf("\n-----------------\n\n");

    printf("Выберите режим игры:\n");
    printf("'1' - один игрок\n'2' - два игрока\n--");
    scanf("%d", &player);

    if(player == 1)
    {
        do
        {
            print_matrix();
            player1_turn();

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
    }

    if(player == 2)
    {
        do
        {
            print_matrix();
            player1_turn();

            done = win_check();

            if(done != SPACE)
            {
                break;
            }

            print_matrix();

            player2_turn();

            done = win_check();
        } while(done == SPACE);

        if(done == 'X')
        {
            printf("\nИгрок 1 выиграл!\n\n");
        }
        else
        {
            printf("\nИгрок 2 выиграл!\n\n");
        }

        print_matrix();
    } 

    return 0;
}