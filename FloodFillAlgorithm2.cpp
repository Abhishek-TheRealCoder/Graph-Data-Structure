// Flood Fill Algorithm
// using DFS
#include<bits/stdc++.h>
using namespace std;
bool isPoss(int i, int j , int n, int m, vector<vector<int>>&grid,vector<vector<int>>&visited, int color){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == color && visited[i][j] == 0)
    {
        return true;
    }
    
    return false;
}

void dfs(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&visited,int newColor){
    
    visited[row][col] = 1;
    int color = grid[row][col];
    grid[row][col] = newColor;

    // left
    int x = row ;
    int y = col - 1;
    if(isPoss(x,y,n,m,grid,visited,color)){
        dfs(x,y,n,m,grid,visited,newColor);
    }
    //right
    x = row ;
    y = col + 1;
    if(isPoss(x,y,n,m,grid,visited,color)){
        dfs(x,y,n,m,grid,visited,newColor);
    }
    
    //up
    x = row - 1 ;
    y = col;
    if(isPoss(x,y,n,m,grid,visited,color)){
        dfs(x,y,n,m,grid,visited,newColor);
    }
    
    //down
    x = row + 1 ;
    y = col;
    if(isPoss(x,y,n,m,grid,visited,color)){
        dfs(x,y,n,m,grid,visited,newColor);
    }
    return;
}


vector<vector<int>>floodFill(vector<vector<int>>&grid,int n,int m, int sr, int sc,int newColor){
    
    vector<vector<int>>visited(n,vector<int>(m,0));
    dfs(sr,sc,n,m,grid,visited,newColor);
    return grid;
}

int main(){
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int n = grid.size();
    int m = grid[0].size();

    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>>ans = floodFill(grid,n,m,sr,sc,newColor);
    
    for(vector<int>res:ans){
        for(auto x:res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}