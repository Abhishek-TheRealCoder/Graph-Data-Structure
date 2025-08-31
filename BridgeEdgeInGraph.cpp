// Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], 
// where edges[i]=[u,v] represents the edge between the vertices u and v. 
// Determine whether a specific edge between two vertices (c, d) is a bridge.

// Note:
// An edge is called a bridge if removing it increases the number of connected components of the graph.
// if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.
// Examples :
// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3]], c = 1, d = 2
// Output: true
// Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in disconnection of the graph.
// Hence, it is a Bridge.

// Input: V = 5, edges[][] = [[0, 1], [0, 3], [1, 2], [2, 0], [3, 4]], c = 0, d = 2
// Output: false
// Explanation:
// Blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph.
// So, it's not a Bridge Edge. All the Bridge Edges in the graph are marked with a green line in the above image.

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>&adj,vector<int>&visited,int target){
    visited[node] = 1;

    if(node == target) return true;
    for(auto neigh:adj[node]){
        if(!visited[neigh]){
            if(dfs(neigh,adj,visited,target)) return true;
        }
    }
    return false;
}
bool isBridge(int V, vector<vector<int>> &edges, int c, int d){
    vector<vector<int>>adj(V);
    for(vector<int>edge:edges){
        int u = edge[0];
        int v = edge[1];
        if(u == c && v == d)continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>visited(V);
    if(dfs(c,adj,visited,d)) return false;
    return true;
}

int main(){
    vector<vector<int>>edges = {
        {0, 1}, {0, 3}, {1, 2}, {2, 0}, {3, 4}
    };
    int c = 0;
    int d = 2;
    int V = 5;
    bool ans = isBridge(V,edges,c,d);
    cout<<ans;
    return 0;
}