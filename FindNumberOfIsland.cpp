#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    bool isPoss(int i, int j, int n, int m,vector<vector<char>>&grid,vector<vector<int>>&visited){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 'L' && visited[i][j] == 0){
            return true;
        }
        return false;
    }
    void dfs(int row,int col,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[row][col] = 1;
        // north
        int x = row - 1;
        int y = col;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        // south
        x = row + 1;
        y = col;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        //west
        x = row;
        y = col - 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        //east
        x = row;
        y = col + 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        
        // north east
        x = row - 1;
        y = col + 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        
        //north west
        x = row - 1;
        y = col - 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        
        //south east
        x = row + 1;
        y = col + 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        
        //south west
        x = row + 1;
        y = col - 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        
        return;
        
    }
    
    int numIslands(int n , int m, vector<vector<char>>&grid){
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 'L' && visited[i][j] == 0){
                    count++;
                    dfs(i,j,n,m,grid,visited);
                }
            }
        }
        return count ;
    }
};

int main(){
    vector<vector<char>>grid={
        {'L','L','W','W','W'},
        {'W','L','W','W','L'},
        {'L','W','W','L','L'},
        {'W','W','W','W','W'},
        {'L','W','L','L','W'}
    };

    int n = grid.size();
    int m = grid[0].size();

    Graph obj;
    int ans = obj.numIslands(n,m,grid);
    cout<<ans<<endl;
}