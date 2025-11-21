#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

int main() {
    cout << "\n Q4: KRUSKAL'S MST \n";

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<tuple<int,int,int>> edges;
    cout << "Enter edges (u v w):\n";

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mst_cost = 0;

    cout << "Edges in MST:\n";

    for (auto& e : edges) {
        int w, u, v;
        tie(w, u, v) = e;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mst_cost += w;
            cout << u << " - " << v << " (w=" << w << ")\n";
        }
    }

    cout << "Total MST Cost = " << mst_cost << "\n";

    return 0;
}
