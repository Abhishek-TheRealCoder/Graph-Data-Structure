#include <bits/stdc++.h>
using namespace std;

vector<int>printPath(vector<vector<int>>&edges,int V){
    vector<vector<pair<int,int>>>adj(V+1);
    for(vector<int>res:edges){
        int u = res[0];
        int v = res[1];
        int w = res[2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int>dist(V+1,INT_MAX);
    vector<int>parent(V+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    
    parent[1] = 1;
    dist[1] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        
        for(auto neigh : adj[node]){
            if(dist[node] + neigh.second < dist[neigh.first]){
                dist[neigh.first] = dist[node] + neigh.second;
                pq.push({dist[node]+neigh.second,neigh.first});
                parent[neigh.first] = node;
            }
        }
    }
    
    if(dist[V] == INT_MAX) return {-1};
    int node = V;
    vector<int>path;
    while(parent[node]!= node){
        path.push_back(node);
        node = parent[node];
    }
    
    path.push_back(1);
    // path.push_back(dist[V]);
    reverse(path.begin(),path.end());
    
    return path;
    
    
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
    vector<int>ans = printPath(edge,vertices);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return  0;
}