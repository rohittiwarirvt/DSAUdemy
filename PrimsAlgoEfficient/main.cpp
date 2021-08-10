#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
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

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  key[0] = 0;
  parent[0] = -1;

  pq.push({0, 0});

  // Run the loop till all the nodes have been visited
  // because in the brute code we checked for mstSet[node] == false while computing the minimum
  // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
  // hence its better to keep running till all the nodes have been taken.
  // try the following case:
  // Credits: Srejan Bera
  // 6 7
  // 0 1 5
  // 0 2 10
  // 0 3 100
  // 1 3 50
  // 1 4 200
  // 3 4 250
  // 4 5 50

  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    mstSet[u] = true;

    for(auto it: adj[u]) {
      int v = it.first;
      int weight = it.second;
      if( mstSet[v] == false && weight < key[v]) {
        parent[v] = u;
        key[v] = weight;
        pq.push({key[v], v});
      }
    }
  }

  for(int i=1; i< V; i++) {
    cout << parent[i] << " - " << i << "\n";
  }
  return 0;
}
