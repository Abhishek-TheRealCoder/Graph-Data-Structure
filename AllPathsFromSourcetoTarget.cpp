// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 
// to node n - 1 and return them in any order.
// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
// (i.e., there is a directed edge from node i to node graph[i][j]).


// Graph + BackTrack
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int target,vector<vector<int>>&ans,vector<int>&res,vector<vector<int>>&adj,vector<int>&visited){
    visited[node] = 1;
    res.push_back(node);

    if(node == target){
        ans.emplace_back(res);
        res.pop_back();
        visited[node] = 0;
        return ;
    }

    for(auto neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh,target,ans,res,adj,visited);
        }
    }
    visited[node] = 0;
    res.pop_back();
    return;
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    int target = n - 1;

    vector<vector<int>>adj(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < graph[i].size();j++){
            adj[i].push_back(graph[i][j]);
        }
    }
    vector<int>visited(n,0);
    vector<vector<int>>ans;
    vector<int>res;
    dfs(0,target,ans,res,adj,visited);
    return ans;
}

int main(){
    vector<vector<int>>graph = {
        {4,3,1},{3,2,4},{3},{4},{}
    };

    vector<vector<int>>ans = allPathsSourceTarget(graph);
    for(vector<int>res:ans){
        for(auto x: res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}