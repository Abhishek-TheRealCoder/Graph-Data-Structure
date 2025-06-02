
#include<bits/stdc++.h>
using namespace std;

int numberOfWays(vector<vector<int>>&edges,int V){
    
    vector<vector<pair<int,int>>>adj(V);
    for(vector<int>res:edges){
        int u = res[0];
        int v = res[1];
        int w = res[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int>dist(V,INT_MAX);
    vector<int>ways(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    pq.push({0,0});
    dist[0] = 0;
    ways[0] = 1;
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        
        for(auto neigh : adj[node]){
            if(neigh.second + dist[node] < dist[neigh.first]){
                dist[neigh.first] = neigh.second + dist[node];
                pq.push({dist[neigh.first] , neigh.first});
                ways[neigh.first] = ways[node];
            }else if(neigh.second + dist[node] == dist[neigh.first]){
                ways[neigh.first] =  ways[neigh.first] +  ways[node];
            }
        }
    }
    
    return ways[V-1];
    
}


int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    
    vector<vector<int>>edge;
    for(int i = 0;i < edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    
    int ans = numberOfWays(edge,vertices);
    cout<<ans;
    return 0;
}