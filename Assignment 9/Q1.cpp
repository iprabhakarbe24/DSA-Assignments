#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "\n Q1: GRAPH REPRESENTATION (Matrix + List) \n";

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adjList(n);
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Enter edges (u v) 0-indexed:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int v : adjList[i]) cout << v << " ";
        cout << "\n";
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }

    int v;
    cout << "\nEnter vertex to find out-degree and in-degree: ";
    cin >> v;

    cout << "Out-degree = " << adjList[v].size() << "\n";

    int indeg = 0;
    for (int i = 0; i < n; i++)
        if (adjMatrix[i][v] == 1)
            indeg++;

    cout << "In-degree = " << indeg << "\n";

    cout << "Adjacent vertices: ";
    for (int x : adjList[v]) cout << x << " ";
    cout << "\n";

    cout << "Number of edges = " << m << "\n";

    return 0;
}
