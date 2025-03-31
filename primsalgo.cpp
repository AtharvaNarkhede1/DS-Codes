#include <iostream>
#include <list>
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
   
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start the algorithm from node 1
    key[1] = 0;

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX, u = -1;

        // Find the minimum node
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && key[v] < mini) {
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
            if (!mst[v] && w < key[v]) {
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
    int n = 5; // Number of nodes
    int m = 7; // Number of edges

    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2}, {{1, 3}, 3}, {{2, 3}, 1}, {{2, 4}, 4}, 
        {{3, 4}, 5}, {{3, 5}, 6}, {{4, 5}, 7}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, edges);

    cout << "Minimum Spanning Tree (MST) edges:\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
