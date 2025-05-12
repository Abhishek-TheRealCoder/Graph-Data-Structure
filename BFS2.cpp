//here we will use maps to store visited or not visited
//here we make sure that there are disconnected components too
#include<bits/stdc++.h>
using namespace std;


class Graph{
    public:
    void solve(int start,vector<vector<int>>&adj,unordered_map<int,bool>&visited,int V,vector<int>&ans){
        queue<int>q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            //for a node go to its neighbour nodes or adjacent nodes
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
    }

    void bfs(int V,vector<vector<int>>&edges){
        //create adjacency list of size V i.e no of
        //considering nodes from 0 To V-1;
        vector<vector<int>>adj(V);
        for(vector<int>edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //by default start from 0.
        vector<int>ans;
        unordered_map<int,bool>visited;
        for(int i = 0;i < V;i++){
            if(!visited[i]){
                solve(i,adj,visited,V,ans);
            }
        }
        //print the bfs traversal
        for(auto it : ans){
            cout<<it<<" ";
        }
    }

};

int main(){
    int edges,vertices;
    cin>>edges>>vertices;
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
    obj.bfs(vertices,edge);
    return 0;
}