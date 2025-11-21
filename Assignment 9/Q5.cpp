#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "\n=== Q6: DIJKSTRA'S ALGORITHM ===\n";

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
        adj[u].push_back(make_pair(v, w));   
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();

        int d    = top.first;
        int node = top.second;

   
        if (d > dist[node]) continue;

       
        for (auto &e : adj[node]) {
            int next = e.first;
            int wt   = e.second;

            if (dist[node] + wt < dist[next]) {
                dist[next] = dist[node] + wt;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    cout << "Shortest distances from " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << "To " << i << ": " << dist[i] << "\n";

    return 0;
}
