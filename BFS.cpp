#include<bits/stdc++.h>
using namespace std;


class Graph{
    public:

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
        queue<int>q;
        vector<int>visited(V,0);
        q.push(0);
        visited[0] = 1;
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            //for a node go to its neighbour nodes or adjacent nodes
            for(auto neigh : adj[node]){
                if(visited[neigh] == 0){
                    q.push(neigh);
                    visited[neigh] = 1;
                }
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