
#include<bits/stdc++.h>
using namespace std;

int sumOfDependencies(vector<vector<int>>&edge,int V){
    int ans = 0;
    vector<vector<int>>adj(V);
    for(vector<int>res:edge){
        int u = res[0];
        int v = res[1];
        adj[u].push_back(v);
    }
    
    for(vector<int>res:adj){
        ans += res.size();
    }
    return ans;
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
    int ans = sumOfDependencies(edge,vertices);
    cout<<ans;
    return 0;
}