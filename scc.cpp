#include <bits/stdc++.h>
using namespace std;
const int N=20000;
vector<int>adj[N];
int sttime[N],fitime[N],comnum[N],vis[N];
int Time=0,cc=0;
void dfs(int v) {

    vis[v] = true;
    sttime[v] = ++Time;
    comnum[v] = cc;
    for( auto to: adj[v] ){
        if(!vis[to]) {
            dfs(to);
        } 
    }

    fitime[v] = ++Time;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;// Number of vertices in the graph
    for(int i = 0; i < m; i++){

        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for( int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cc++;

            dfs(i);
        }
    }

    for(int i = 0; i < n; i++){
        cout<<i<<": "<<comnum[i]<<' '<<sttime[i]<<' '<<fitime[i]<<endl;
    }


    return 0;
}
