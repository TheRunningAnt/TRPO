#include "tic-tac-toe.h"
#include "ctest.h"
#include <stdio.h>

#define SPACE ' '

CTEST (check_coordinate_true, coordinate_check)
{	
	char mat[3][3] = {
        {SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE}
	};
	int x = 2;
    int y = 2;
    int result = coordinate_check(x, y);

    const int expected = 0;
    ASSERT_EQUAL (expected, result);
}

CTEST (check_coordinate_false, coordinate_check)
{	
	char mat[3][3] = {
        {SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE}
	};
	int x = 5;
    int y = 2;
    int result = coordinate_check(x, y);

    const int expected = -1;
    ASSERT_EQUAL (expected, result);
}

CTEST (check_space_true, is_space_check)
{	
	char mat[3][3] = {
        {'X', SPACE, SPACE},
        {SPACE, '0', SPACE},
        {SPACE, 'X', SPACE}
	};
	int x = 1;
    int y = 2;
    int result = is_space_check(x, y, mat);

    const int expected = 0;
    ASSERT_EQUAL (expected, result);
}

CTEST (check_space_false, is_space_check)
{	
	char mat[3][3] = {
        {'X', SPACE, SPACE},
        {SPACE, 'O', SPACE},
        {SPACE, 'X', SPACE}
	};
	int x = 3;
    int y = 2;
    int result = is_space_check(x, y, mat);

    const int expected = -1;
    ASSERT_EQUAL (expected, result);
}