#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool bipartiteDFS(int node, vector<int> adj[], int color[]) {
    for ( auto it: adj[node]) {
        if (color[it] == -1) {
            color[it] = 1 - color[node];
            if (!bipartiteDFS(it, adj, color)) {
                return false;
            }
        } else if(color[it] == color[node]) return false;
    }
    return true;
}
bool checkBipartite(vector<int> adj[], int V) {
    int color[V];
    memset(color, -1, sizeof color);
    for (int i=0; i < V; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            if (!bipartiteDFS(i, adj, color)) {
                return false;
            }
        }
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0;i<E;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite(adj, E)) {
        cout << "yes";
    } else {
        cout << "No";
    }
    return 0;
}
