#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int column, vector<string> &board, vector<vector<string>> &ans, vector<int> leftRow, vector<int> upperDiagonal, vector<int> lowerDiagonal, int n) {
    if (column == n) {
        ans.push_back(board);
        return ;
    }

    for (int row =0; row < n; row++) {
        if (leftRow[row] == 0 && lowerDiagonal[row + column] ==0 && upperDiagonal[n -1 + column -row] == 0) {
            board[row][column] = 'Q';
            leftRow[row] =1;
            lowerDiagonal[row +column] = 1;
            upperDiagonal[n -1 + column - row] =1;
            solve(column +1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][column] ='.' ;
            leftRow[row] =0;
            lowerDiagonal[row +column] =0 ;
            upperDiagonal[n -1 + column -row] =0;
        }
    }
}

int main()
{

    int n =4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i =0; i< n;i++) {
        board[i] = s;
    }
    vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}
