#include <bits/stdc++.h>
using namespace std;

void findEulerPath(vector<vector<int>>& g, int v, vector<int>& path) {
    for (int u = 0; u < g.size(); ++u) {
        while (g[v][u] > 0) {
            --g[v][u];
            findEulerPath(g, u, path);
        }
    }
    path.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m; // Input number of vertices and edges

    vector<vector<int>> g(n, vector<int>(n, 0)); // Initialize the adjacency matrix

    // Read the graph in the adjacency matrix
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; // Input edge (u, v)
        g[u][v]++; // Assuming 1 indicates the presence of an edge
    }

    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];
    }

    int first = 0;
    while (first < n && !deg[first])
        ++first;

    vector<int> path;
    findEulerPath(g, first, path);
    reverse(path.begin(), path.end());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j])
                cout << "Graph has an Eulerian path!" << endl;
        }
    }

    for (int x : path)
        cout << x << " ";

    return 0;
}
