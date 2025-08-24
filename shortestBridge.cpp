// Problem Link->https://leetcode.com/problems/shortest-bridge/?envType=problem-list-v2&envId=matrix
// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
// An island is a 4-directionally connected group of 1's not connected to any other 1's. 
// There are exactly two islands in grid.
// You may change 0's to 1's to connect the two islands to form one island.
// Return the smallest number of 0's you must flip to connect the two islands.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1

#include<bits/stdc++.h>
using namespace std;


bool isPoss(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0 && visited[i][j] == 0) return true;
    return false;
}

bool isPoss2(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && visited[i][j] == 0) return true;
    return false;
}


void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited,queue<pair<pair<int,int>,int>>&q){
    visited[i][j] = 1;
    q.push(make_pair(make_pair(i,j),0));
    //north
    int x = i - 1;
    int y = j;
    if(isPoss2(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,q);
    }

    //south
    x = i + 1;
    y = j;
    if(isPoss2(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,q);
    }

    //east
    x = i;
    y = j + 1;
    if(isPoss2(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,q);
    }

    //west
    x = i;
    y = j - 1;
    if(isPoss2(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,q);
    }

    return;
}

int bfs(int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited,queue<pair<pair<int,int>,int>>&q){

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        //north
        int x = row - 1;
        int y = col;

        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) return dist;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1; 
        }
        //south
        x = row + 1;
        y = col;
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) return dist;   if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1; 
        }

    //east
        x = row;
        y = col - 1;
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) return dist;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1; 
        }
        //west
        x = row;
        y = col + 1;
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]) return dist;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1; 
        }       
    }

    return 0;
}
int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>visited(n,vector<int>(m,0));
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                dfs(i,j,n,m,grid,visited,q);
                return bfs(n,m,grid,visited,q);
            }
        }
    }
    return -1;
}


int main(){
    vector<vector<int>>arr = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    int ans = shortestBridge(arr);
    cout<<ans;
    return 0;
}