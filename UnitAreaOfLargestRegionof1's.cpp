// Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
// Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).

// Example 1:
// Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
// Output: 5
// Explanation: The grid is-
// 1 1 1 0
// 0 0 1 0
// 0 0 0 1
// The largest region of 1's is colored
// in orange.

// Example 2:
// Input: grid = {{0,1}}
// Output: 1
// Explanation: The grid is-
// 0 1
// The largest region of 1's is colored in 
// orange.

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && !visited[i][j])return true;
    return false;
}
void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited,int &count){
    count++;
    visited[i][j] = 1;
    
    //north
    int x = i - 1;
    int y = j;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //north - east
    x = i - 1;
    y = j + 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //north - west
    x = i - 1;
    y = j - 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    
    //south
    x = i + 1;
    y = j;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //south - east
    x = i + 1;
    y = j + 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //south - west
    x = i + 1;
    y = j - 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //east
    x = i;
    y = j + 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //west
    x = i;
    y = j - 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    return ;
}
// Function to find unit area of the largest region of 1s.
int findMaxArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int maxi = 0;
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                int count = 0;
                dfs(i,j,n,m,grid,visited,count);
                maxi = max(maxi,count);
            }
        }
    }
    return maxi;
}

int main(){
    vector<vector<int>>arr = {{1,1,1,0},{0,0,1,0},{0,0,0,1}};
    int ans = findMaxArea(arr);
    cout<<ans;
    return 0;
}