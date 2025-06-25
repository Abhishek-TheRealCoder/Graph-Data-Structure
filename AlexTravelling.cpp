
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(vector<int>edge : flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
        
        //apply Dijkstra ALgo
        vector<int>dist(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push(make_pair(k,0));
        dist[k] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            q.pop();
            
            for(auto neigh : adj[node]){
                
                if(dist[node] + neigh.second < dist[neigh.first]){
                    
                    dist[neigh.first] = dist[node] + neigh.second;
                    
                    q.push(make_pair(neigh.first,dist[neigh.first]));
                }
                
            }
        }
        
        int maxi = -1;
        for(int i = 1;i < n+1;i++){
            maxi = max(maxi,dist[i]);
        }
        
        if(maxi == INT_MAX) return -1;
        return maxi;
    }
};
int main(){
    int vertices,edge;
    cin >> vertices >>edge;
    vector<vector<int>>edges;
    for(int i = 0;i < edge;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    int k;
    cin>>k;
    Graph obj;
    int ans = obj.minimumCost(edges,vertices,k);
    cout<<ans;
    return 0;
}