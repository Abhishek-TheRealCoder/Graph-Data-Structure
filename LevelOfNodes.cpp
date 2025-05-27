
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int levelOfNode(vector<vector<int>>&edge,int V,int x)
{
    vector<vector<int>>adj(V);
    for(vector<int>res:edge){
        int u = res[0];
        int v = res[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
     queue<pair<int,int>>q;
        vector<int>visited(V,0);
        visited[0] = 1;
        q.push({0,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node == x) return level;
    
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    q.push({neigh,level+1});
                    visited[neigh] = 1;
                }
            }
        }
        return -1;
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
    int target;
    cin>>target;
    int ans = levelOfNode(edge,vertices,target);
    cout<<ans;
    return 0;
}