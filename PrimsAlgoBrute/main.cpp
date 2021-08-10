#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

  int V,E;
	cin >> V >> E;
	vector<pair<int,int> > adj[V];

	int u,v,wt;
	for(int i = 0; i<E ; i++){
		cin >> u >> v >> wt;
		adj[u].push_back(make_pair(v,wt));
		adj[v].push_back(make_pair(u,wt));
	}

  int parent[V];

  int key[V];

  bool mstSet[V];

  for(int i=0; i < V; i++) {
    key[i] = INT_MAX, mstSet[i] = false;
  }

  key[0] =0;
  parent[0] = -1;
  int ansWeight = 0;

  for(int count=0; count < V -1; count++ ) {
    int mini = INT_MAX, u;

    for(int v =0; v < V; v++) {
      if (mstSet[v] == false && key[v] < mini ) {
        mini = key[v];
        u = v;
      }
    }
    mstSet[u] = true;

    for( auto it: adj[u]) {
      int v = it.first;
      int weight = it.second;
      if(mstSet[v] == false && weight < key[v]) {
        parent[v] = u, key[v] = weight;
      }
    }
  }

  for (int i = 1; i < V; i++)
    cout << parent[i] << " - " << i <<" \n";
  return 0;
}
