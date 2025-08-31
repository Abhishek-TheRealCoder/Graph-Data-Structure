// A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
// Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path 
// starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathVisited,vector<int>&checkSafe){
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto neigh : adj[node]){
        if(!visited[neigh]){
            if(dfs(neigh,adj,visited,pathVisited,checkSafe)) return true;
        }
        else if(pathVisited[neigh] == 1) return true;
    }

    checkSafe[node] = 1;
    pathVisited[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<vector<int>>&edges) {
    vector<vector<int>>adj(V);
    for(vector<int>edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<int>visited(V,0);
    vector<int>pathVisited(V,0);
    vector<int>checkSafe(V,0);

    for(int i = 0;i < V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,pathVisited,checkSafe);
        }
    }
    vector<int>ans;
    for(int i = 0;i < V;i++){
        if(checkSafe[i] == 1){
            ans.emplace_back(i);
        }
    }
    return ans;
}

int main(){
    int edge,vertices;
    cin>>edge>>vertices;

    vector<vector<int>>edges;
    for(int i = 0;i < edge;i++){
        int u,v;
        cin>>u>>v;  
        edges.push_back({u,v});
    }   

    vector<int>ans = eventualSafeNodes(vertices,edges);
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}