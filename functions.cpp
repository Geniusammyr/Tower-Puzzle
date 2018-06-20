#include "functions.h"

vector<int> colToRow(int board[5][5], int col, vector<int> fauxRow)
{
    int i;
    fauxRow.clear();
    for (i = 0; i < 5; i++)
    {
        fauxRow.push_back(board[i][col]);
    }
    return fauxRow;
}

bool validCol(vector<int> testVector)
{
    int i;
    bool used[5];
    for (i = 0; i < 5; i++)
    {
        used[i] = false;
    }
    for (i = 0;  i < 5; i++)
    {
        if (testVector[i] != 0 && used[testVector[i] - 1])
        {
            return false;
        }
        used[i] = true;
    }
    return true;
}

void getSolveNumbers(vector<vector<int>> &lines)
{
    int i;
    int inputNum;

    //top, left, right, bottom lines are 0, 1, 2, 3 repectively
    lines.resize(4);

    cout << "Enter numbers the same way you would read them: ";
    cout << "\n(Starting at the top left, go across the row and then down, repeat.) \n";
    for (i = 0; i < 5; i++)
    {
        cin >> inputNum;
        lines[0].push_back(inputNum);
    }


    //enter in the middle rows
    for (i = 0; i < 5; i++)
    {
        cin >> inputNum;
        lines[1].push_back(inputNum);
        cin >> inputNum;
        lines[2].push_back(inputNum);
    }

    //enter in the middle rows
    for (i = 0; i < 5; i++)
    {
        cin >> inputNum;
        lines[3].push_back(inputNum);
    }
}

bool mainRecurse(int board[5][5], bool used[5][5], vector<vector<int>>visibleTowers)
{
    int tempX, tempY;

    //if on the last step, add current position to arrays and return true
    if (totalSteps == pow(size, 2))
    {
        solution[x][y] = totalSteps;
        stepped[x][y] = true;
        return true;
    }

        //if the adjusted coordinates are a valid move,
        //call knights tour with that new position
    if (possibleMove(size, tempX, tempY, stepped))
        {
            solution[x][y] = totalSteps;
            stepped[x][y] = true;
            if (knightsTour(size, tempX, tempY,
                stepped, solution, totalSteps + 1))
            {
                //ultimately returns true for the whole function
                //by breaking the recursion
                return true;
            }

            //if a solution was not found by the recusive call above,
            //reset the board to before the previous call was made
            solution[x][y] = 0;
            stepped[x][y] = false;
        }
    }

    //if no solution is found, return false
    return false;
}
