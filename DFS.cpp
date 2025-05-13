#include<bits/stdc++.h>
using namespace std;
class Graph{
    private:
    void solve(int start,vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans){
        //start from the node 0
        visited[start] = 1;
        ans.push_back(start);
        for(auto neigh : adj[start]){
            if(!visited[neigh]){
                solve(neigh,adj,visited,ans);
            }
        }
    }
    public:
    void dfs(int V,vector<vector<int>>&edges){
        //create adjacency list of size V i.e no of nodes
        //considering nodes from 0 To V-1;
        vector<vector<int>>adj(V);
        for(vector<int>edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //by default start from 0.
        vector<int>visited(V,0);
        // there are only connected components
        // to store the dfs traversal we declare a vector ans
        vector<int>ans;

        if(!visited[0]){
            solve(0,adj,visited,ans);
        }
        //print the dfs traversal
        for(auto it : ans){
            cout<<it<<" ";
        }
    }
};

int main(){
    int edges,vertices;
    vector<vector<int>>edge;
    for(int i = 0;i < edges;i++){
        vector<int>temp;
        int u;
        int v;
        cin>>u>>v;
        temp={u,v};
        edge.push_back(temp);
    }
    Graph obj;
    obj.dfs(vertices,edge);
}