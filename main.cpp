#include "functions.h"

int main()
{
	clock_t runTime;
    int i, j;
    int board[5][5];
    bool used[5][5];
    int visibleTowers[4][5];

	

    //initialize arrays for solving
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            board[i][j] = 0;
            used[i][j] = false;
        }
    }

	getSolveNumbers(visibleTowers);

	runTime = clock();

	mainRecurse(board, used, visibleTowers, 0);
    
	cout << "\n" << clock() - runTime << " ms runtime of main recursion\n";

    return 0;
}
