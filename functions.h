#ifndef  _FUNCTIONS_H__
#define _FUNCTIONS_H__


#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

vector<int> colToRow(int board[5][5], int col, vector<int> newRow);
bool validCol(vector<int> testVector);
void getSolveNumbers(vector<vector<int>> &lines);
bool mainRecurse(int board[5][5], bool used[5][5], vector<vector<int>>visibleTowers)

#endif