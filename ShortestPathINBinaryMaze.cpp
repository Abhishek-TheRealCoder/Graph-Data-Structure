

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i, int j , int n, int m ,vector<vector<int>>&visited,vector<vector<int>> &grid){
    if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 0 && grid[i][j] == 1){
        return true;
    }
    return false;
}

int shortestPathInBinaryMaze(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination){
    int n = grid.size();
    int m = grid[0].size();
    int startRow = source.first;
    int startCol = source.second;
    
    int destRow = destination.first;
    int destCol = destination.second;

    vector<vector<int>>visited(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(startRow,startCol),0));

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if(row == destRow && col == destCol){
            return dist;
        }
        
        //north
        int x = row - 1;
        int y = col ;
        if(isPoss(x,y,n,m,visited,grid)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        //south 
        x = row + 1;
        y = col ;
        if(isPoss(x,y,n,m,visited,grid)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        //east
        x = row;
        y = col - 1;
        if(isPoss(x,y,n,m,visited,grid)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        //west
        x = row;
        y = col + 1;
        if(isPoss(x,y,n,m,visited,grid)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
    
    }
    return -1;
}


int main(){
    vector<vector<int>>grid = 
    {   {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };

    int n = grid.size();
    int m = grid[0].size();

    pair<int,int>source = {0,1};
    pair<int,int>dest = {2,2};
    
    int ans = shortestPathInBinaryMaze(grid,source,dest);
    cout<<ans<<endl;
    return 0;
}