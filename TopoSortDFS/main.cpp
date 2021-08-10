#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class Solutions {
  public:
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
      vis[node] =1;
      for(auto it: adj[node]) {
        if (!vis[it]) {
          findTopoSort(it, vis, st, adj);
        }
      }
      st.push(node);
    }

    vector<int> topoSort(int N, vector<int> adj[]) {
      stack<int> st;
      vector<int> vis(N, 0);

      for (int i=0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }

      vector<int> topo;
      while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;
    }


};


/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}


int main() {
  int T;
  cin >> T;
  while (T--) {
      int V, E;
      cin >> V >> E;
      int u, v;

      vector<int> adj[V];

      for (int i = 0; i < E; i++) {
          cin >> u >> v;
          adj[u].push_back(v);
      }

      Solutions obj;
      vector <int> res = obj.topoSort(V, adj);

      cout << check(V, res, adj) << endl;
  }
  return 0;
}
