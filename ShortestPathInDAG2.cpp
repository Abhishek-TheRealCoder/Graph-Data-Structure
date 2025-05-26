
// here i will Solve ShortestPathInDAG with Dijkstra's algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int>shortestPath(vector<vector<int>>&edges,int V){
    vector<vector<pair<int,int>>>adj(V);
    for(vector<int>res:edges){
        int u = res[0];
        int v = res[1];
        int wt = res[2];
        adj[u].push_back(make_pair(v,wt));
    }
    
    
    vector<int>dist(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(make_pair(0,0));

    dist[0] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node]!=INT_MAX){
            for(auto neigh : adj[node]) {
                if(dist[node] + neigh.second < dist[neigh.first]){
                    dist[neigh.first] = dist[node] + neigh.second;
                    pq.push(make_pair(dist[neigh.first], neigh.first));
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