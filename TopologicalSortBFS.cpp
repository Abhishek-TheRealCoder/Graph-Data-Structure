
// Kahn's algorithm for topological sorting using BFS
// topological sort is for ONLY directed acyclic graphs (DAGs).

#include<bits/stdc++.h>
using namespace std;

vector<int>topoLogicalSortBFS(vector<vector<int>>&edges,int V){
    vector<vector<int>>adj(V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<int>indegree(V,0);
    for(int i = 0;i < V;i++){
        for(auto neigh:adj[i]){
            indegree[neigh]++;
        }
    }

    queue<int>q;
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){
                q.push(neigh);
            }
        }
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
    vector<int>topo = topoLogicalSortBFS(edgesList, vertices);
    for(auto node : topo){
        cout << node << " ";
    }
    return 0;
}