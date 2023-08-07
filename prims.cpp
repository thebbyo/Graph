#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2000;
vector<int> adj[N];
int n;
bool vis[N];

int primMST() {
    vector<int> dist(n, INT_MAX), parent(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int TotalWeight = 0;
    int StartVerrtex = 0;
    pq.push({0, StartVerrtex});
    dist[StartVerrtex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        vis[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int weingt = adj[u][i + 1]; // The next element is the weight

            if (!vis[v] && weingt < dist[v]) {
                dist[v] = weingt;
                parent[v] = u;
                pq.push({dist[v], v});
            }

            i++; // Skip the weight for the next iteration
        }
    }

    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) TotalWeight += dist[i];
    }

    return TotalWeight;
}

int main() {
    int m;
    cin >> n >> m;

    // Reset the vis array before each call to primMST
    memset(vis, false, sizeof(vis));

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adj[u].push_back(w); // Add weight to the adjacency list
        adj[v].push_back(w); // Add weight to the adjacency list
    }

    cout << primMST();
    return 0;
}
