#include <iostream>

using namespace std;

void BFS(vector<int> adj[], int V, int src) {
  int dist[V];
  for(int i=0; i< V;i++) {
    dis[i] = INT_MAX;
  }

  dist[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for( auto it: adj[node]) {
      if (dist[node] + 1 < dist[it]) {
        dist[it] = dist[node] +1;
        q.push(it);
      }
    }
  }

  for(int i =0; i< V; i++) {
    cout << dist[i] << " ";
  }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
