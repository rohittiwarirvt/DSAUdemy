#include <iostream>

int parent[100000];
int rank[100000];

using namespace std;

void makeSet() {
  for (int i= 1; i <=n;i++) {
    parent[i] =i;
    rank[i] = 0;
  }
}

// 7->6-> 4->3
int findPar(int node) {
  if (node == parent[node]) {
    return node;
  }
  return parent[node] = findPar(parent[node]);
}

void union(int u, int v) {
  u = findPar(u);
  v = findPar(v);

  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[u] > rank[v]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}


int main() {
  makeSet();
  return 0;
}
