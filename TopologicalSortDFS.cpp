// topological sort is for ONLY directed acyclic graphs (DAGs).
// Topological Sort using DFS
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,stack<int>&s){
    visited[node] = 1;
    for(auto neigh:adj[node]){
        if(!visited[neigh]){
            dfs(neigh, visited, adj, s);
        }
    }
    s.push(node);
}

vector<int>topoLogicalSortDFS(vector<vector<int>>&edges,int V){
    vector<vector<int>>adj(V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    vector<int>visited(V, 0);
    stack<int>s;
    for(int i = 0;i < V;i++){
        if(!visited[i]){
            dfs(i,visited,adj,s);
        }
    }
    vector<int>topo;
    while(!s.empty()){
        topo.push_back(s.top());
        s.pop();
    }

    return topo;
}


int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    vector<vector<int>>edgesList;
    for(int i = 0;i < edges;i++){
        int u,v;
        cin >> u >> v;
        edgesList.push_back({u,v});
    }
    vector<int>topo = topoLogicalSortDFS(edgesList, vertices);
    for(auto node : topo){
        cout << node << " ";
    }

    return 0;
}