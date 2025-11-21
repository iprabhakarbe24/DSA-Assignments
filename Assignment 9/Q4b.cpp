#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "\n Q5: PRIM'S MST \n";

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> vis(n, false);

   
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int start = 0;
    pq.push(make_pair(0, start));

    int mst_cost = 0;

    cout << "Edges in MST:\n";

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();

        int w   = top.first;     
        int node = top.second; 

        if (vis[node]) continue;
        vis[node] = true;
        mst_cost += w;

        cout << "Pick node " << node << " with weight " << w << "\n";

        for (auto &edge : adj[node]) {
            int next = edge.first;
            int wt   = edge.second;

            if (!vis[next]) {
                pq.push(make_pair(wt, next));
            }
        }
    }

    cout << "Total MST Cost = " << mst_cost << "\n";
    return 0;
}
