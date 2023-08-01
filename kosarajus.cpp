#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Graph{
    int v;
    vector<vector<int> >adj;
    public:
        Graph(int v): v(v), adj(v){}
    void addEdge(int u, int w){
        adj[u].push_back(w);
    }
  
void DFS(int v, vector<bool> &visited, stack<int> &finishedStack) {
    visited[v] = true;
    for (auto neighbour : adj[v]) {
        if (!visited[neighbour])
            DFS(neighbour, visited, finishedStack);
    }
    finishedStack.push(v);
}


    void DFSutil(int v, vector<bool> &visited, vector<int> &scc){
        visited[v] = true;
        scc.push_back(v);
        for(auto neighbour:adj[v]){
            if(!visited[neighbour]) DFSutil(neighbour, visited, scc);
        }

    }

    Graph getTranspose(){
        Graph transpose(v);
        for(int i =0;i<v;i++){
            for(auto neighouur:adj[i]) transpose.addEdge(neighouur, i);
        }
        return transpose;
    }

    void printSCCs(){
        vector<bool> visited(v, false);
        stack<int> finishedStack;
        for(int i = 0;i<v; i++){
            if(!visited[i]) DFS(i, visited, finishedStack);
        }
        
        Graph transpose = getTranspose();
        fill(visited.begin(), visited.end(), false);

        while (!finishedStack.empty()){
            int v = finishedStack.top();
            finishedStack.pop();
            if(!visited[v]){
                vector<int> scc;
                transpose.DFSutil(v, visited, scc);
                printSCC(scc);
            }
        }  
    }

    void printSCC(vector<int> &scc){
        for(auto x:scc) cout<<x<<" ";
        cout<<endl;
    }
};

int main(){
    Graph graph(6);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,0);
    graph.addEdge(3,2);
    graph.addEdge(3,4);
    graph.addEdge(4,2);
    graph.addEdge(3,5);

    graph.printSCCs();

    return 0;
}