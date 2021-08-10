#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

  int V, E, source;
  cin >> V >> E;
  vector<pair<int, int>> graph[V +1]; // 1 - indexed adjacency list for the graph

  int v, e, wt;

  for(int i=0; i < V; i++) {
    cin >> v >> e >> wt;
    graph[v].push_back(make_pair(e, wt));
    graph[e].push_back(make_pair(v, wt));
  }

  cin >> source;

  // Dijkstra's algorithm begins from here

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap ; In pair =>(dist, from )
  vector<int> distTo(V +1, INT_MAX); // 1-indexed array for calculating shortest paths;

  distTo[source] = 0;

  pq.push(make_pair(0, source)); // (dist, from )

  while (!pq.empty()) {
    int dist = pq.top().first;
    int prev = pq.top().second; //
    pq.pop();

    vector<pair<int, int>>::iterator it;

    for( it = graph[prev].begin(); it != graph[prev].end(); it++) {
      int next = it->first;
      int nextDist = it->second;
      if( distTo[next] > distTo[prev] + nextDist) {
        distTo[next] = distTo[prev] + nextDist;
        pq.push(make_pair(distTo[next], next));
      }
    }
  }

  cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";

  return 0;
}
