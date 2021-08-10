#include <iostream>
#include<bits/stdc++.h>


using namespace std;

bool isSafe(int row , int col, vector<string> board, int n) {
    // check the upper diagonal
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--; col--;
    }

    col = dupcol;
    row = duprow;
    while( col >=0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while(row <n && col >=0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }
}

void solve(int column, vector<string> &board, vector<vector<string>> &ans, int n) {
    if(column == n) {
        ans.push_back(board);
        return ;
    }

    for (int row =0; row < n; row++ ) {
        if (isSafe(row, column, board, n)) {
            board[row][column] = 'Q';
            solve(column +1, board, ans, n);
            board[row][column] = '.';
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

    solve(0, board, ans, n);
    return 0;
}
