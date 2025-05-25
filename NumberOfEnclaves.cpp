

// DFS
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i, int j, int n,int m, vector<vector<int>>&visited,vector<vector<int>>&grid){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && visited[i][j] == 0) return true;
    
    return false;
}


void dfs(int row, int col,int n, int m,vector<vector<int>>&visited,vector<vector<int>>&grid){
    visited[row][col] = 1;

    // north
    int x = row - 1;
    int y = col;
    if(isPoss(x, y, n, m, visited, grid)){
        dfs(x, y, n, m, visited, grid);
    }

    // south
    x = row + 1;
    y = col;
    if(isPoss(x, y, n, m, visited, grid)){
        dfs(x, y, n, m, visited, grid);
    }

    //east
    x = row;
    y = col - 1;
    if(isPoss(x, y, n, m, visited, grid)){
        dfs(x, y, n, m, visited, grid);
    }

    //west
    x = row;
    y = col + 1;
    if(isPoss(x, y, n, m, visited, grid)){
        dfs(x, y, n, m, visited, grid);
    }
}


int numberOfEnclaves(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                ans++;
            }
        }
    }
    return ans;
}



int main(){
    vector<vector<int>>grid = {
        {0, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    };
    int n = grid.size();
    int m = grid[0].size();
    
    int ans = numberOfEnclaves(grid);
    cout<<ans;
    return 0;
}