#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
vector<int> adj[N];
vector<int> transpose[N];
int vis[N], transVis[N];
int n, m;
stack<int> finishedStack;

void dfs(int v) {
    vis[v] = true;
    for (auto neighbour : adj[v]) {
        if (!vis[neighbour]) dfs(neighbour);
    }
    finishedStack.push(v);
}

void dfsTrans(int v, vector<int> &scc) {
    transVis[v] = true;
    scc.push_back(v);
    for (auto neighbour : transpose[v]) {
        if (!transVis[neighbour]) dfsTrans(neighbour, scc);
    }
}

void getTranspose() {
    for (int i = 0; i < n; i++) {
        for (auto neighbour : adj[i]) {
            transpose[neighbour].push_back(i);
        }
    }
}

void printSCC(vector<int> &scc) {
    for (auto x : scc) cout << x << " ";
    cout << endl;
}

void printSCCs() {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    getTranspose();
    while (!finishedStack.empty()) {
        int v = finishedStack.top();
        finishedStack.pop();
        if (!transVis[v]) {
            vector<int> scc;
            dfsTrans(v, scc);
            printSCC(scc);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n >> m; // Number of vertices and edges in the graph

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    printSCCs();

    return 0;
}
