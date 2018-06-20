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

    mainRecurse(board, used, visibleTowers)
    getSolveNumbers(visibleTowers);
    

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {

            //set values
            //try to recurse down
            //undo on way back
        }
    }

    return 0;
}