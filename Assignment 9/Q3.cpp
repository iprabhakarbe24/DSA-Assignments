#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    cout << node << " ";

    for (int nb : adj[node]) {
        if (!vis[nb])
            dfsUtil(nb, adj, vis);
    }
}

int main() {
    cout << "\n=== Q3: DFS ===\n";

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

    vector<bool> vis(n, false);

    cout << "DFS Traversal: ";
    dfsUtil(start, adj, vis);
    cout << "\n";

    return 0;
}
