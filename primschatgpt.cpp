#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> primsMST(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u][v] = w;
        adj[v][u] = w;
    }
    
    vector<int> key(n + 1, INT_MAX);
    vector<bool> inMST(n + 1, false);
    vector<int> parent(n + 1, -1);
    
    key[1] = 0;
     
    for (int count = 1; count < n; count++) {
        int minKey = INT_MAX, u = -1;
        
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        
        inMST[u] = true;
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    
    vector<pair<int, int>> mst;
    for (int i = 2; i <= n; i++) {
        if (parent[i] != -1)
            mst.push_back({parent[i], i});
    }
    return mst;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {1, 2, 2}, {1, 3, 3}, {2, 3, 1}, {2, 4, 4}, 
        {3, 4, 5}, {3, 5, 6}, {4, 5, 7}
    };
    
    vector<pair<int, int>> mst = primsMST(n, edges);
    
    cout << "Minimum Spanning Tree (MST) edges:\n";
    for (auto &edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }
    return 0;
}
