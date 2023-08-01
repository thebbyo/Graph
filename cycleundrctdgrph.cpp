#include <iostream>
#include <vector>

using namespace std;

class Graph {
protected:
    int v;
    vector<vector<int> > adj;

public:
    Graph(int v) : v(v), adj(v) {}
    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    void print() {
        for (int i = 0; i < v; i++) {
            cout << i << ": ";
            for (auto x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

class UndirectedCyclicGraph : public Graph {
public:
    UndirectedCyclicGraph(int v) : Graph(v) {}
    bool isCycle() {
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++) {
            if (!visited[i] && isCycleUtil(i, visited, -1))
                return true;
        }
        return false;
    }

private:
    bool isCycleUtil(int v, vector<bool> &visited, int parent) {
        visited[v] = true;
        for (auto neighbour : adj[v]) {
            if (!visited[neighbour] && isCycleUtil(neighbour, visited, v))
                return true;
            else if (neighbour != parent)
                return true;
        }
        return false;
    }
};
class DirecedIsCycleGraph: public Graph{
    public: DirecedIsCycleGraph(int v): Graph(v){}
    void addEdge(int u, int w){
        adj[u].push_back(w);
    }
        bool isCycle(){
         vector<bool> visited(v,false), recursion(v, false);
         for(int i=0;i<v;i++){
            if(!visited[i] && isCyclicUtil(i, visited, recursion)) return true;
         }
         return false;
        }
    private:
        bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recursion){
            visited[v] = recursion[v] = true;
            for(auto neighbour: adj[v]){
                if(!visited[neighbour] && isCyclicUtil(neighbour, visited, recursion)) return true;
                else if(recursion[neighbour]) return true;
            }
            recursion[v] = false;
            return false;
        }

};
int main() {
    DirecedIsCycleGraph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    cout << (graph.isCycle() ? "cycle" : "no cycle") << endl;

    return 0;
}
