#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
vector<int> adj[N];
int n;
bool vis[N];

void dfs(int v) {
    vis[v] = true;
    for (auto neighbour : adj[v]) {
        if (!vis[neighbour])
            dfs(neighbour);
    }
}

bool isConnected() {
	//memset(vis, false, sizeof(vis));
	dfs(0);
	for(int i=0;i<n;i++) {
		if(!vis[i]) return false;
	}
	return true;
}
int isEulerian(){
	if(!isConnected()) return 0;
	int odd =0;
	for(int i=0;i<n;i++){
		if(adj[i].size() &1) odd++;
	}
	if(odd>2) return 0;
	return (odd)? 1:2;
}
void test(){
	if(isEulerian() ==0) cout<<"Not Eulerian\n";
	else if(isEulerian() == 1) cout<<"Euler path\n";
	else cout<<"Euler Circuit\n";
}
int main() {
    int m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    test();
    return 0;
}
