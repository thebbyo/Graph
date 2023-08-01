#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
vector<int> adj[N];
int vis[N];
stack<int> ans;
void dfs(int v){
	vis[v] = true;
	for(auto neighbour:adj[v]){
		if(!vis[neighbour]) dfs(neighbour);
	}
	ans.push(v);
}
int main()
{
	int n, m;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	while(!ans.empty()){
		cout<<ans.top()<<" ";
		ans.pop();
	}
	cout<<endl;
	return 0;
}