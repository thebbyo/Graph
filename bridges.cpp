#include <bits/stdc++.h>
using namespace std;

const int N = 20000;
vector<int> adj[N];
int vis[N], low[N], start[N];
int n,m;
int t =1;
vector<pair<int, int>> brdge;
void dfs(int v, int parent){
    vis[v] = true;
    start[v] = low[v] = t++;
    for(auto to:adj[v]){
        if(parent == to) continue;
  if(vis[to]){
            low[v] = min(low[v], start[to]);
        }
        else{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            //cout<<v<<' '<<to<<' '<<' '<<low[v]<<' '<<start[to]<<endl;
            if(low[to] > start[v]) brdge.push_back({v, to});
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){

        if(!vis[i]) dfs(i,-1);
    }
    for(auto a : brdge) cout<<a.first<<" "<<a.second<<endl;
    return 0;
}
