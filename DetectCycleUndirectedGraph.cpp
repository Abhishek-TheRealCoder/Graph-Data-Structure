// Detect Cycle in Undirected Graph using BFS

#include<bits/stdc++.h>
using namespace std;

bool bfs(int start,vector<vector<int>>&adj,vector<int>&visited){
    queue<pair<int,int>>q;
    q.push(make_pair(start,-1));
    visited[start] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                q.push(make_pair(neigh,node));
                visited[neigh] = 1;
            }else{
                if(parent != neigh) return true;
            }
        }
    }
    return false;
    
}

bool detectCycle(vector<vector<int>>&edge,int V){
    
    vector<vector<int>>adj(V);
    for(vector<int>res:edge){
        int u = res[0];
        int v = res[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>visited(V,0);
    for(int i = 0;i < V;i++){
        if(!visited[i]){
            if(bfs(i,adj,visited)) return true;
        }    
    }
    return false;
    
}


int main(){
    int edges,vertices;
    cin>>edges>>vertices;
    
    vector<vector<int>>edge;
    for(int i = 0;i < edges; i++){
        int u,v;
        cin>>u>>v;
        edge.push_back({u,v});
    }
    bool ans = detectCycle(edge,vertices);
    cout<<ans<<endl;
    return 0;
}

