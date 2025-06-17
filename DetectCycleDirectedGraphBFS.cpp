// solving if there is cycle in directed graph using BFS (KAHN's algorithm)
// Kahn's algorithm for topological sorting using BFS
// topological sort is for ONLY directed acyclic graphs (DAGs).

#include<bits/stdc++.h>
using namespace std;


bool isCycle(vector<vector<int>>&edges,int V){
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
    
    if(topo.size() != V) return true; // Cycle detected
    return false; // No cycle detected
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
    bool ans = isCycle(edgesList, vertices);
    cout<<ans;
    return 0;
}