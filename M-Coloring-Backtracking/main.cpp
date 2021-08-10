#include <iostream>

using namespace std;

bool isSafe(int node, int colour[], bool graph[101][101], int m, int col, ) {
    for ( int k=0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && colour[k] == col) {
            return false;
        }
    }
    return false;
}

bool solve( int node, int colour[], int m , in N, bool graph[101][101]) {
    if ( node == N) {
        return true;
    }

    for (int i=1; i <= m; i++) {
        if(isSafe(node, colour, graph, N, i)) {
            colour[node] = i;
            if ( solve( node +1, color, m, N, graph)) return true;
            colour[node] = 0;
        }
    }

    return false;
}
int main()
{

    int  N = 4;
    int M = 3;
    int E = 5;
    vector<pair <int, int>> Edges = {(1,2),(2,3),(3,4),(4,1),(1,3)};
    int colour[N] = {0};
    if (solve(0, color, m, N, graph)) return true;
    return false;
}
