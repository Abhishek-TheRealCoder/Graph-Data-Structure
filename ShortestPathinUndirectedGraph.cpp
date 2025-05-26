
#include<bits/stdc++.h>
using namespace std;


vector<int>shortestPath(vector<vector<int>>&edges,int V,int src){
    vector<vector<int>>adj(V);
    for(vector<int>res:edges){
        int u = res[0];
        int v = res[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int>q;
    q.push(src);

    vector<int>dist(V,INT_MAX);
    dist[src] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto neigh : adj[node]){
            if(dist[node] + 1 < dist[neigh]){
                dist[neigh] = 1 + dist[node];
                q.push(neigh);
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
        int u,v;
        cin>>u>>v;
        edge.push_back({u,v});
    }
    int src ;
    cin>>src;
    vector<int>ans = shortestPath(edge,vertices,src);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return  0;
}   