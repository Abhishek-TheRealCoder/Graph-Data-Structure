
// Prerequisite-Tasks
#include<bits/stdc++.h>
using namespace std;


bool prereq(vector<vector<int>>&prerequisites,int V){
    vector<vector<int>>adj(V);
    for(vector<int>res:prerequisites){
        int u = res[0];
        int v = res[1];
        adj[u].push_back(v);
    }
    
    vector<int>indegree(V,0);
    for(int i = 0;i < V;i++){
        for(auto neigh : adj[i]){
            indegree[neigh]++;
        }
    }
    
    queue<int>q;
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto neigh:adj[node]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){
                q.push(neigh);
            }
        }
    }
    if(topo.size()==V) return true;
    return false;
}

int main() {
    int vertices,edges;
    cin>>vertices>>edges;
    
    vector<vector<int>>prerequisites;
    for(int i = 0;i < edges;i++){
        int task1,task2;
        cin>>task1>>task2;
        prerequisites.push_back({task1,task2});
    }
    
    bool ans = prereq(prerequisites,vertices);
    cout<<ans<<" ";
}