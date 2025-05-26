
// Shortest Path in a Directed Acyclic Graph (DAG) using Topological Sort
// This code implements the shortest path algorithm in a DAG using topological sorting.
// Alternative approach -> use Dijkstra's algorithm if the graph is a DAG I.E there is no cycle in the graph.
#include<bits/stdc++.h>
using namespace std;

void dfs_topo(int start,vector<int>&visited,vector<vector<pair<int,int>>>&adj,stack<int>&s){
    
    visited[start] = 1;
    for(auto neigh:adj[start]){
        if(!visited[neigh.first]){
            dfs_topo(neigh.first,visited,adj,s);
        }
    }
    s.push(start);
    return;
}

vector<int>shortestPath(vector<vector<int>>&edges,int V){
    vector<vector<pair<int,int>>>adj(V);
    for(vector<int>res:edges){
        int u = res[0];
        int v = res[1];
        int wt = res[2];
        adj[u].push_back(make_pair(v,wt));
    }
    
    //dfs Topological sort
    stack<int>s;
    vector<int>visited(V);
    for(int i = 0;i < V;i++){
        if(!visited[i]){
            dfs_topo(i,visited,adj,s);
        }
    }
    vector<int>dist(V,INT_MAX);
    dist[0] = 0;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        
        if(dist[node]!=INT_MAX){
            for(auto neigh : adj[node]) {
                if(dist[node] + neigh.second < dist[neigh.first]){
                    dist[neigh.first] = dist[node] + neigh.second;
                }
            }  
        }
         
    }
    
    for(int i = 0;i < V;i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;    
}

int main() {
    int vertices,edges;
    cin>>vertices>>edges;
    
    vector<vector<int>>edge;
    for(int i = 0;i < edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge.push_back({u,v,wt});
    }
    
    vector<int>ans = shortestPath(edge,vertices);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return  0;
}   