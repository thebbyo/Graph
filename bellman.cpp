#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 200000;
vector<pii> adj[N];
int n,m;
bool vis[N];
void BellmanFord(int source){
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(auto edge:adj[u]){
                int v = edge.first;
                int w = edge.second;

                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u]+ w;
                }
            }
        }
    }
    for(int u=0;u<n;u++){
        for(auto edge:adj[u]){
            int v = edge.first;
            int w = edge.second;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                cout<<"has a negative weight cycle\n";
                return;
            }
        }
    }
   for(int i=0;i<n;i++){
        cout<<i<<": "<<dist[i]<<endl;
    }
}

int main() {
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int source;
    cin>>source;
     BellmanFord(source);
    
    return 0;
}
