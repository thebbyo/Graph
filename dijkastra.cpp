#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int> > > adj;

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v, int weight) {
        adj[u].push_back( {v, weight});
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 6; // Number of vertices in the graph
    Graph graph(V);

    // Adding edges to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 6);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 8);

    int src = 0; // Source vertex

    vector<int> shortestDistances = graph.dijkstra(src);

    // Printing the shortest distances from the source vertex to all other vertices
    cout << "Shortest distances from vertex " << src << " to all other vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
