// BFS
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
    void bfs(int row,int col,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&visited){
        
        queue<pair<int,int>>q;
        q.push(make_pair(row,col));
        visited[row][col] = 1;
        
        while(!q.empty()){
            int newRow = q.front().first;
            int newCol = q.front().second;
            q.pop();
            
            // north
            int x = newRow - 1;
            int y = newCol;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            // south
            x = newRow + 1;
            y = newCol;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            //west
            x = newRow;
            y = newCol - 1;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            //east
            x = newRow;
            y = newCol + 1;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            
            // north east
            x = newRow - 1;
            y = newCol + 1;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            
            //north west
            x = newRow - 1;
            y = newCol - 1;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            
            //south east
            x = newRow+ 1;
            y = newCol + 1;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
            
            //south west
            x = newRow + 1;
            y = newCol - 1;
            if(isPoss(x,y,n,m,grid,visited)){
                q.push(make_pair(x,y));
                visited[x][y] = 1;
            }
        }
    }
    
    int numIslands(int n , int m, vector<vector<char>>&grid){
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 'L' && visited[i][j] == 0){
                    count++;
                    bfs(i,j,n,m,grid,visited);
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