#include <iostream>
#include <climits>
#include <set>
#include <vector>

using namespace std;

class Graph {
    int adj[50][50];

public:
    Graph() {
        for (int i = 0; i < 50; ++i)
            for (int j = 0; j < 50; ++j)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w; // Undirected
    }

    void printGraph(int vertices) {
        cout << "\nGraph Adjacency Matrix:\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "[ ";
            for (int j = 0; j < vertices; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << "]\n";
        }
    }

    void printPath(int node, vector<int>& parent) {
        if (node == -1) return;
        printPath(parent[node], parent);
        cout << node << " -> ";
    }

    void dijkstra(int start, int vertices) {
        vector<int> dist(vertices, INT_MAX);
        vector<int> parent(vertices, -1);
        set<pair<int, int>> s;

        dist[start] = 0;
        s.insert({0, start});

        while (!s.empty()) {
            auto [d, u] = *s.begin();
            s.erase(s.begin());

            for (int v = 0; v < vertices; ++v) {
                if (adj[u][v]) {
                    int newDist = d + adj[u][v];
                    if (newDist < dist[v]) {
                        s.erase({dist[v], v}); // Remove if already present
                        dist[v] = newDist;
                        parent[v] = u;
                        s.insert({newDist, v});
                    }
                }
            }
        }

        cout << "\nShortest Distances from Home (0):\n";
        for (int i = 0; i < vertices; ++i)
            cout << "Marriage Hall " << i << " : " << dist[i] << "\n";

        cout << "\nPaths:\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "Path to Marriage Hall " << i << " : ";
            if (dist[i] == INT_MAX)
                cout << "No path";
            else if (i == start)
                cout << "Already at Home";
            else {
                printPath(i, parent);
                cout << "END";
            }
            cout << "\n";
        }

        int nearest = -1, minDist = INT_MAX;
        for (int i = 1; i < vertices; ++i) {
            if (dist[i] < minDist) {
                minDist = dist[i];
                nearest = i;
            }
        }

        if (nearest != -1)
            cout << "\nNearest Marriage Hall: " << nearest << " at distance " << minDist << "\n";
        else
            cout << "\nNo reachable Marriage Hall found.\n";
    }
};

int main() {
    int vertices, edges;
    cout << "Enter number of Marriage Halls: ";
    cin >> vertices;
    cout << "Enter number of Routes: ";
    cin >> edges;     

    Graph g;
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cout << "\nRoute " << i + 1 << ":\n";
        cout << "From (0 for Home): "; cin >> u;
        cout << "To: "; cin >> v;
        cout << "Distance: "; cin >> w;
        g.addEdge(u, v, w);
    }

    g.printGraph(vertices);
    g.dijkstra(0, vertices);

    return 0;
}
