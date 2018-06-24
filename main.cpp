#include "functions.h"

int main()
{
    int i, j;
    int board[5][5];
    bool used[5][5];
    vector<vector<int>> visibleTowers;

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
    
    

    return 0;
}
