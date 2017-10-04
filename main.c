#include <stdio.h>
#include <stdlib.h>

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

        done = check();

        if(done != SPACE)
        {
            break;
        }

        computer_turn();

        done = check();
    } while(done == SPACE);
}