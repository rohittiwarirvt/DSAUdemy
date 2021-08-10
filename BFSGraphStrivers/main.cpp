#include <iostream>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V +1, 0);

    for(int i=1 ; i<= V; i++) {
        if(!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it: adj[node]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] =1;
                    }
                }
            }
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}