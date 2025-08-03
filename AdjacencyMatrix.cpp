// storing edges in matrix form i.e Adjacency matrix
// Adjacency matrix represents the edge between two nodes or vertices 
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    int adj[vertices+1][vertices+1] = {{}};
    for(int i = 0;i < edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout<<"printing edges in matrix form"<<endl;

    for(int i = 0;i < vertices+1 ;i++){
        for(int j = 0;j < vertices+1 ;j++){
            cout<<adj[i][j]<<" ";
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