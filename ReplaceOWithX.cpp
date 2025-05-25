
// DFS
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i, int j, int n,int m, vector<vector<int>>&visited,vector<vector<char>>&grid){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 'O' && visited[i][j] == 0) return true;
    
    return false;
}


void dfs(int row,int col,int n,int m,vector<vector<int>>&visited,vector<vector<char>>&grid){
    visited[row][col] = 1;

    // all 4 directions
    //north
    int x = row - 1;
    int y = col;
    if(isPoss(x,y,n,m,visited,grid)){
        dfs(x,y,n,m,visited,grid);
    }
    //south
    x = row + 1;
    y = col;
    if(isPoss(x,y,n,m,visited,grid)){
        dfs(x,y,n,m,visited,grid);
    }


    //west
    x = row;
    y = col + 1;
    if(isPoss(x,y,n,m,visited,grid)){
        dfs(x,y,n,m,visited,grid);
    }

    //east
    x = row;
    y = col - 1;
    if(isPoss(x,y,n,m,visited,grid)){
        dfs(x,y,n,m,visited,grid);
    }
    return ;
}
vector<vector<char>>fill(vector<vector<char>>&grid,int n, int m){
    
    // go to all boundary cells and if you find 'O' then mark all its connected to visited
    vector<vector<int>>visited(n,vector<int>(m,0));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(grid[i][j] == 'O' && visited[i][j] == 0){
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 'O' && visited[i][j] == 0){
                grid[i][j] = 'X';
            }
        }
    }

    return grid;
}

int main(){
    vector<vector<char>>grid = {
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<char>>ans = fill(grid,n,m);
    for(vector<char>res:ans){
        for(auto x: res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}