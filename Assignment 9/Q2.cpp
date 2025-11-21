#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& adj, int start) {
    vector<bool> vis(adj.size(), false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int nb : adj[node]) {
            if (!vis[nb]) {
                vis[nb] = true;
                q.push(nb);
            }
        }
    }
    cout << "\n";
}

int main() {
    cout << "\n Q2: BFS \n";

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  
        adj[v].push_back(u);  
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(adj, start);

    return 0;
}
