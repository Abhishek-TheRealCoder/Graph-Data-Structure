// Given a matrix mat[][] with r rows and c columns, where some cells are landmines (marked as 0) and others are 
// safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell 
// in the rightmost column of the mat. You cannot move diagonally, and you must avoid both the landmines and their 
// adjacent cells (up, down, left, right), as they are also unsafe.

// Example 1:
// Input:
// mat = [1, 0, 1, 1, 1],
//       [1, 1, 1, 1, 1],
//       [1, 1, 1, 1, 1],
//       [1, 1, 1, 0, 1],
//       [1, 1, 1, 1, 0]
// Output: 
// 6
// Explanation: 
// We can see that length of shortest
// safe route is 6
// [1 0 1 1 1]
// [1 1 1 1 1]
// [1 1 1 1 1]
// [1 1 1 0 1] 
// [1 1 1 1 0]

// Example 2:
// Input:
// mat = [1, 1, 1, 1, 1],
//       [1, 1, 0, 1, 1],
//       [1, 1, 1, 1, 1]
// Output: 
// -1
// Explanation: There is no possible path from
// first column to last column.
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i ,int j,int n,int m,vector<vector<int>> &mat,vector<vector<int>>&visited){
    if( i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != 0 && visited[i][j] == 0) return true;
    return false;
}
int bfs(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<int>>&visited){
    
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(i,j),1));
    visited[i][j] = 1;
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(col == m - 1){
            return dist;
        }
        //north
        
        int x = row - 1;
        int y = col;
        if(isPoss(x,y,n,m,mat,visited)){
            q.push(make_pair(make_pair(x,y),dist+1));
            visited[x][y] = 1;
        }
        //south
        x = row + 1;
        y = col;
        if(isPoss(x,y,n,m,mat,visited)){
            q.push(make_pair(make_pair(x,y),dist+1));
            visited[x][y] = 1;
        }
        //east
        x = row;
        y = col + 1;
        if(isPoss(x,y,n,m,mat,visited)){
            q.push(make_pair(make_pair(x,y),dist+1));
            visited[x][y] = 1;
        }
        
        //west
        x = row ;
        y = col - 1;
        if(isPoss(x,y,n,m,mat,visited)){
            q.push(make_pair(make_pair(x,y),dist+1));
            visited[x][y] = 1;
        }
    }
    return 1e9;
}

int findShortestPath(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    vector<pair<int,int>> walls;

    // collect all 0 positions
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0) walls.push_back({i,j});
        }
    }
    for(auto [i,j]: walls){
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k=0;k<4;k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                mat[ni][nj] = 0;
            }
        }
    }
    
    
    int mini = 1e9;
    for(int i = 0;i < n;i++){
        if(mat[i][0] == 0) continue;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int ans = bfs(i,0,n,m,mat,visited);
        mini = min(mini,ans);
    }
    return mini == 1e9 ? -1 : mini;
}

int main(){
    vector<vector<int>>mat ={
      {1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 0, 1},
      {1, 1, 1, 1, 0}
    };
    int ans = findShortestPath(mat);
    cout<<ans;
    return 0;
}