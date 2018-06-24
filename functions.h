#ifndef  _FUNCTIONS_H__
#define _FUNCTIONS_H__


#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

int * colToRow(int board[5][5], int col, int newRow[5]);
bool validCol(int testCol[5]);
void getSolveNumbers(vector<vector<int>> &lines);
bool mainRecurse(int board[5][5], bool used[5][5],
	vector<vector<int>>visibleTowers, int timeNum);
void printBoard(int board[5][5]);
bool validBoard(int board[5][5], vector<vector<int>> visibleTowers);
bool validVisible(int testRow[5], int expectedLeft, int expectedRight);

#endif
