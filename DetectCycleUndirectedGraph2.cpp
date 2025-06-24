// Detect Cycle in Undirected Graph using DFS
#include <bits/stdc++.h>
using namespace std;

bool dfs(int start, vector<vector<int>>& adj, vector<int>& visited, int parent) {
    visited[start] = 1;

    for (auto neigh : adj[start]) {
        if (!visited[neigh]) {
            if (dfs(neigh, adj, visited, start)) return true;
        } else if (neigh != parent) {
            return true;  // Cycle found
        }
    }

    return false;
}

bool detectCycleDFS(vector<vector<int>>& edges, int V) {
    vector<vector<int>> adj(V);

    // Build adjacency list from edge list
    for (auto &res : edges) {
        int u = res[0];
        int v = res[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, -1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int edges, vertices;
    cin >> edges >> vertices;

    vector<vector<int>> edge;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
    }

    bool ans = detectCycleDFS(edge, vertices);
    cout << (ans ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
