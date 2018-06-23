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
    for (i = 0; i < 5; i++)
    {
        if (testVector[i] != 0 && used[testVector[i] - 1])
        {
			//if number in non-zero and repeated, the test is failed
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

bool mainRecurse(int board[5][5], bool used[5][5],
	vector<vector<int>>visibleTowers, int timeNum)
{
	vector<int> newRow;
	int i, j;
	int currentRow, currentCol;
	int tempNum = 0;	
	if (timeNum == 25)
	{
		printBoard(board);
		//check if correct towers are visible
		return true;
	}

	//do the math to find our where the next num goes
	currentRow = timeNum / 5;
	currentCol = timeNum % 5;

	for (i = 0; i < 5; i++)
	{
		newRow.clear();
		if (!used[currentRow][i])
		{
			used[currentRow][i] = true;
			board[currentRow][currentCol] = i + 1;
			


			cout << timeNum << " ";
			printBoard(board);

			for (j = 0; j < 5; j++)
			{
				cout << used[currentRow][j] << " ";
			}
			cout << "\n\n";



			if (validCol(colToRow(board, currentCol, newRow)))
			{
				//cout << "recursing with timeNum as " << timeNum+1 << " and i as " << i << "\n";
				//printBoard(board);
				cout << timeNum << " ";
				printBoard(board);

				for (j = 0; j < 5; j++)
				{
					cout << used[currentRow][j] << " ";
				}
				cout << "\n\n";

				mainRecurse(board, used, visibleTowers, timeNum + 1);
				
				//cout << "unrecursing with timeNum as " << timeNum << " and i as " << i << "\n";	
			}
			used[currentRow][i] = false;
			board[currentRow][currentCol] = 0;
		}
	}
	return false;
}
 
void printBoard(int board[5][5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
