// Dijkstra Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int>dijkstraAlgorithm(vector<vector<int>>&edges,int V,int src){
    
    vector<vector<pair<int,int>>>adj(V);
    for(vector<int>res:edges){
        int u = res[0];
        int v = res[1];
        int w = res[2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(make_pair(0,src));
    
    vector<int>dist(V,INT_MAX);
    dist[src] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        
        for(auto neigh : adj[node]){
            int wt = neigh.second;
            if(dist[neigh.first] > wt + dist[node]){
                dist[neigh.first] = wt + dist[node];
                pq.push(make_pair(wt,neigh.first));
            }
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
    int src ;
    cin>>src;
    vector<int>ans = dijkstraAlgorithm(edge,vertices,src);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return  0;
}   