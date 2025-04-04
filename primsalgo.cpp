#include <iostream>
#include <list>
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;

vector<pair<pair<int, int>, int>> 
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
   
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);


    for(int i=0; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }


    key[1] = 0; // Starting node
    parent[1] = -1; // Starting node has no parent

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX; 
        int u;

        // Find the minimum node
        for (int v = 1; v <= n; v++) {
            if (mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark the minimum node as true
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v]) {
               parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main() {
    int n, m;
    vector<pair<pair<int, int>, int>> g;

    // Example input (number of nodes and edges)
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    // Input edges in the form: (u, v, weight)
    cout<<"Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({{u, v}, w});
    }

    // Call the Prim's algorithm function
    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    // Print the MST
    cout << "Edges in MST:\n";
    for (auto &edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;

}