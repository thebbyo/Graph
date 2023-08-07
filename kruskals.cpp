#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 20000;
int size[N];
int parent[N];
vector<pii> adj[N];
void make(int v){
    parent[v] = v;
    size[v] =1;
}
int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) {
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n, m;
    cin>>n>>m;
    vector<pair<int,pii>>adj;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({w, {u,v}});
        adj.push_back({w, {v,u}});


    }
    sort(adj.begin(),adj.end());
    int cost = 0;
    for(int i=0;i<n;i++) make(i);
        for(auto adj:adj){
            int w = adj.first;
            int u = adj.second.first;
            int v = adj.second.second;
            if(find(u) == find(v)) continue;
            Union(u,v);
            cost+=w;
            cout<<u<<" "<<v<<endl;
        }
        cout<<cost<<endl;
    return 0;
}
