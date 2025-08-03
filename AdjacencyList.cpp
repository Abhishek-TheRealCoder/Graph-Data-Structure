// storing edges in matrix form i.e Adjacency list to reduce space from () to Space = (2E)
// Adjacency matrix represents the edge between two nodes or vertices 
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>>adj(vertices+1);
    for(int i = 0;i < edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    cout<<"printing edges in list form"<<endl;

    for(vector<int>edge:adj){
        for(auto x: edge){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}
// vertices edges
//    5      6
//    1      2
//    2      5
//    2      4
//    1      3
//    4      5
//    3      4 