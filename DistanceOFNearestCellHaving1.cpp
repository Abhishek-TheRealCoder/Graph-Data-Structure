// BFS
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i, int j, int n,int m, vector<vector<int>>&visited,vector<vector<int>>&grid){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0 && visited[i][j] == 0) return true;
    
    return false;
}

vector<vector<int>>nearest(vector<vector<int>>&grid,int n, int m){
    
    vector<vector<int>>ans(n,vector<int>(m,0));
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
           if(grid[i][j] == 1){
               visited[i][j] = 1;
               q.push(make_pair(make_pair(i,j),0));
           }
        }
    }
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second;
        ans[row][col] = d;
        
        q.pop();
        
        //north
        int x = row - 1;
        int y = col;
        if(isPoss(x,y,n,m,visited,grid)){
            visited[x][y] = 1;
            q.push(make_pair(make_pair(x,y),d + 1));
        }
        
        //south
        x = row + 1;
        y = col;
        if(isPoss(x,y,n,m,visited,grid)){
            visited[x][y] = 1;
            q.push(make_pair(make_pair(x,y),d + 1));
        }
        
        //east
        x = row ;
        y = col - 1;
        if(isPoss(x,y,n,m,visited,grid)){
            visited[x][y] = 1;
            q.push(make_pair(make_pair(x,y),d + 1));
        }
        
        // west
        x = row ;
        y = col + 1;
        if(isPoss(x,y,n,m,visited,grid)){
            visited[x][y] = 1;
            q.push(make_pair(make_pair(x,y),d + 1));
        }
    }
    
    return ans;
}

int main(){
    vector<vector<int>>grid = {
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>>ans = nearest(grid,n,m);
    for(vector<int>res:ans){
        for(auto x: res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}