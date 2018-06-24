#include "functions.h"

int main()
{
	clock_t runTime;
    int i, j;
    int board[5][5];
    bool used[5][5];
    vector<vector<int>> visibleTowers;

	runTime = clock();

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
	mainRecurse(board, used, visibleTowers, 0);
    
	cout << "\n" << clock() - runTime << " ms runtime";

    return 0;
}
