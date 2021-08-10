#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> topoSortBFSKahns(int V, vector<int> adj[]) {
      queue<int> q;
      vector<int> indegree(V, 0);
      for(int i =0; i < V; i++) {
        for (auto it: adj[i]) {
          indegree[i]++;
        }
      }

      for (int i=0; i < V; i++) {
        if (indegree[i] == 0) {
          q.push(i);
        }
      }

      vector<int> topo;

      int cnt =0;
      while (!q.empty()) {
        int node= q.front();
        q.pop();
        cnt++;
        topo.push_back(node);
        for (auto it: adj[node]) {
          indegree[it]--;
          if (indegree[it] == 0) {
            q.push(it);
          }
        }
      }
      if (cnt == V) return false;
      return topo;
    }
};
int main() {
  int t;
  cin >> t;
  while(t--) {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> res = obj.topoSortBFSKahns(V, adj);
    for (auto it: res) {
      cout << it << " ";
    }
  }
    return 0;
}
