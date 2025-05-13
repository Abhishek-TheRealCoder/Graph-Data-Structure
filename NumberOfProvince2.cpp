// BFS

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    void bfs(int start,vector<vector<int>>&adj,unordered_map<int,bool>&visited){
        queue<int>q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            //for a node go to its neighbour nodes or adjacent nodes
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
        return ;
    }

    int numberOfProvinces(int V,vector<vector<int>>&edges){

        vector<vector<int>>adj(V);
        for(vector<int>edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool>visited;
        int count = 0;

        for(int i = 0;i < V;i++){
            if(!visited[i]){
                count = count + 1;
                bfs(i,adj,visited);
            }
        }
        return count;

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
    int ans = obj.numberOfProvinces(vertices,edge);
    cout<<ans<<endl;
    return 0;
}

