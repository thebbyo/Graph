#include <bits/stdc++.h>
using namespace std;

int n, m;

void floydWarshall(vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][via] < INT_MAX && dist[via][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
    graph = dist;
}

int main() {
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydWarshall(graph);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (graph[i][j] == INT_MAX ? -1 : graph[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}
