// if edges are given in form of 2D array
// [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6],[6,7],[7,8],[8,9]]
//DFS
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    void dfs(int start,vector<vector<int>>&adj,unordered_map<int,bool>&visited){

        visited[start] = true;
        for(auto neigh : adj[start]){
            if(!visited[neigh]){
                dfs(neigh,adj,visited);
            }
        }
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
                dfs(i,adj,visited);
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
