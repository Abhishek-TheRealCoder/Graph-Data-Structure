// Flood Fill Algorithm
// using BFS
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i, int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>>&visited,int cellColor){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == cellColor && visited[i][j] == 0){
        return true;
    }
    return false;
}

vector<vector<int>>floodFill(vector<vector<int>> &grid,int n ,int m,int sr, int sc, int newColor){
    
    vector<vector<int>>visited(n,vector<int>(m,0));
    int oldColor = grid[sr][sc];
    visited[sr][sc] = 1;
    
    //row,col,colorOntheCell
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(sr,sc),oldColor));
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int color = q.front().second;
        grid[row][col] = newColor;
        q.pop();
        
        //left
        int x = row;
        int y = col - 1;
        if(isPoss(x,y,n,m,grid,visited,color)){
            q.push(make_pair(make_pair(x,y),color));
            visited[x][y] = 1;
        }
        //right
        x = row;
        y = col + 1;
        if(isPoss(x,y,n,m,grid,visited,color)){
            q.push(make_pair(make_pair(x,y),color));
            visited[x][y] = 1;
        }
        
        //up
        x = row - 1;
        y = col;
        if(isPoss(x,y,n,m,grid,visited,color)){
            q.push(make_pair(make_pair(x,y),color));
            visited[x][y] = 1;
        }
        
        //down
        x = row + 1;
        y = col;
        if(isPoss(x,y,n,m,grid,visited,color)){
            q.push(make_pair(make_pair(x,y),color));
            visited[x][y] = 1;
        }
    }
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
    
    for(vector<int>res:grid){
        for(auto x:res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}