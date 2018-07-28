#include "functions.h"

//take in the board and a column, and turn that column into a "row"
//so it can be checked using functions expecting a row
int * colToRow(int board[5][5], int col, int newRow[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        newRow[i] = (board[i][col]);
    }
    return newRow;
}


//Check that column does not contain any duplicate numbers, with zeros as
//blanks that don't count as duplicates
bool validCol(int testCol[5])
{
    int i;
    bool used[5];

	//initialize used array for testing
    for (i = 0; i < 5; i++)
    {
        used[i] = false;
    }


    for (i = 0; i < 5; i++)
    {
        if (testCol[i] != 0 && used[testCol[i] - 1])
        {
			//if number in non-zero and repeated, the test is failed
            return false;
        }
		if (testCol[i] != 0)
		{
			//set the non-zero as already seen
			used[testCol[i] - 1] = true;
		}
    }
    return true;
}


//retreives the visible tower numbers from the user,
//and store them in an array
void getSolveNumbers(int lines[4][5])
{
    int i;
    int inputNum;

    //top, left, right, bottom lines are [0], [1], [2], and [3] repectively

    cout << "Enter numbers the same way you would read them: ";
    cout << "\n(Starting at the top left, go across the row and then down, repeat.) \n";

	//enter the top row
    for (i = 0; i < 5; i++)
    {
        cin >> inputNum;
        lines[0][i] = inputNum;
    }
	cout << "\n";

    //enter in the middle rows
    for (i = 0; i < 5; i++)
    {
        cin >> inputNum;
        lines[1][i] = inputNum;
        cin >> inputNum;
        lines[2][i] = inputNum;
    }

    //enter in the end row
    for (i = 0; i < 5; i++)
    {
        cin >> inputNum;
		lines[3][i] = inputNum;
    }
}


//sole recursion function
bool mainRecurse(int board[5][5], bool used[5][5],
	int visibleTowers[4][5], int timeNum)
{
	int newRow[5];
	int i, j;
	int currentRow, currentCol;
	int tempNum = 0;	
	if (timeNum == 25)
	{
		//if completed board that fits visible towers
		if (validBoard(board, visibleTowers))
		{
			//spit the board out to user
			printBoard(board);
		}
		return true;
	}

	//do the math to find our where the next num goes
	currentRow = timeNum / 5;
	currentCol = timeNum % 5;

	for (i = 0; i < 5; i++)
	{
		if (!used[currentRow][i])
		{
			used[currentRow][i] = true;
			board[currentRow][currentCol] = i + 1;
			if (validCol(colToRow(board, currentCol, newRow)))
			{
				mainRecurse(board, used, visibleTowers, timeNum + 1);
			}
			used[currentRow][i] = false;
			board[currentRow][currentCol] = 0;
		}
	}
	return false;
}
 

//print the board(solution)
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


//check is the current board state is possible using visible towers
bool validBoard(int board[5][5], int visibleTowers[4][5])
{
	int i;
	int tempRow[5];

	//check cols to see  if valid
	for (i = 0; i < 5; i++)
	{
		if(!validVisible(board[i],
			visibleTowers[1][i], visibleTowers[2][i]))
		{
			return false;
		}
	}

	//convert cols to "rows" and check if they are valid
	for (i = 0; i < 5; i++)
	{
		if(!validVisible(colToRow(board, i, tempRow),
			visibleTowers[0][i], visibleTowers[3][i]))
		{
			return false;
		}
	}
	
	return true;
}


//check if a given line of numbers is a possible solution
bool validVisible(int testRow[5], int expectedLeft, int expectedRight)
{
	int visibleLeft = 1;
	int visibleRight = 1;
	int tallestTower, i;

	//step from left checking how many towers are visible
	tallestTower = testRow[0];
	for (i = 1; i < 5; i++)
	{
		if (testRow[i] > tallestTower)
		{
			visibleLeft++;
			tallestTower = testRow[i];
		}
	}

	//step from right checking how many towers are visible
	tallestTower = testRow[4];
	for (i = 3; i >= 0; i--)
	{
		if (testRow[i] > tallestTower)
		{
			visibleRight++;
			tallestTower = testRow[i];
		}
	}
	return (visibleLeft == expectedLeft && visibleRight == expectedRight);
}


//spit out an example of a proper run of the programs
void printExample()
{
	int i, j;
	int visableTowers[4][5] = { { 2, 3, 2, 1, 2 },
		{3, 1, 3, 2, 2}, {2, 4, 3, 4, 1}, {2, 2, 3, 4, 1} };

	int solution[5][5] = { {2, 1, 3, 5, 4}, {5, 4, 1, 3, 2},
		{1, 2, 5, 4, 3}, {3, 5, 4, 2, 1}, {4, 3, 2, 1, 5} };

	int exampleInput[20] = { 2, 3, 2, 1, 2, 3, 2, 1, 4, 3,
		3, 2, 4, 2, 1, 2, 2, 3, 4, 1 };

	//output example input as a single line of numbers
	cout << "Example input:\n";
	for (i = 0; i < 20; i++)
	{
		cout << exampleInput[i] << " ";
	}

	//output example input as a square
	cout << "\n\n";
	for (i = 0; i < 5; i++)
	{
		cout << visableTowers[0][i] << "   ";;
	}
	cout << "\n";
	for (i = 0; i < 5; i++)
	{
		cout << visableTowers[1][i];
		cout << "\t\t";
		cout << visableTowers[2][i];
		cout << "\n";
	}
	for (i = 0; i < 5; i++)
	{
		cout << visableTowers[3][i] << "   ";
	}
	cout << "\n\nExample Output:\n\n";

	//print example solution output
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << solution[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
