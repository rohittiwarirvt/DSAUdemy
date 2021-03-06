#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int i, int j, vector<vector<int>> &matrix, int size, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[] ) {
    if (i == size-1 && j == size-1) {
        ans.push_back(move);
        return ;
    }
    string dir = "DLRU";
    for(int ind=0; ind < 4 ; ind++) {
        int nexti = i + di[i];
        int nextj = j + di[j];
        if ( nexti >=0 && nextj>= 0 && nexti < size && nextj < size  && !vis[nexti][nextj] && ans[nexti][nextj] == 1) {
            vis[i][j] = 1;
            solve(nexti, nextj, matrix, size, ans, move + dir[ind], vis, di, dj);
            vis[i][j] =0;
        }
    }
    // downward
    // if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
    //     vis[i][j] = 1;
    //     solve(i+1, j, a, n, ans, move + 'D', vis);
    //     vis[i][j] = 0;
    // }

    // // left
    // if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1) {
    //     vis[i][j] = 1;
    //     solve(i, j-1, a, n, ans, move + 'L', vis);
    //     vis[i][j] = 0;
    // }

    // // right
    // if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
    //     vis[i][j] = 1;
    //     solve(i, j+1, a, n, ans, move + 'R', vis);
    //     vis[i][j] = 0;
    // }

    // // upward
    // if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1) {
    //     vis[i][j] = 1;
    //     solve(i-1, j, a, n, ans, move + 'U', vis);
    //     vis[i][j] = 0;
    // }
}
int main()
{

    int size = 4;
    vector<vector<int>> matriz_maze =
         {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    vector<string> ans;
    vector<vector<int>> vis(size, vector<int> (size, 0));
    int di[] = { +1, 0, 0, -1};
    int dj[] = { 0, -1, 1, 0};
    if (matriz_maze[0][0] ==1 ) solve(0, 0, matriz_maze, size, ans, "", vis, di, dj);

    return 1;
}
