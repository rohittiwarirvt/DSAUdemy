#include <iostream>
#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;


void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]) {
  vis[node] =1;
  for(auto it: adj[node]) {
    if (!vis[it.first]) {
      findTopoSort(it.second, vis , st, adj);
    }
  }
  st.push(node);
}

void shortestPath(int src, int V, vector<pair<int, int>> adj[]) {
  int vis[V] = {0};
  stack<int> st;
  for(int i=0; i < V; i++ ) {
    if (!vis[i]) {
      findTopoSort(i, vis, st, adj);
    }
  }

  int dist[V];
  for (int i =0; i < V; i++) {
    dist[i] = 1e9;
  }

  dist[src] = 0;

  while(!st.empty()) {
    int node = st.top();
    st.pop();

    if (dist[node] != INF) {
      for (auto it: adj[node]) {
        if (dist[node] + it.second < dist[it.first]) {
          dist[it.first] = dist[node] + dist[node];
        }
      }
    }
  }

  for (int i =0; i < V; i++) {
    (dist[i] == 1e9) ? cout << "INF ": cout << dist[i] << " ";
  }
}


int main()
{
  int V, E;

  cin >> V >> E;

  vector<pair<int, int>> adj[V];

  for (int i =0; i< E; i++) {
    int v, e, wt;
    cin >> v >> e >> wt;
    adj[v].push_back({e, wt});
  }

  shortestPath(0, V, adj );

  return 0;
}
