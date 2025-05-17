// 0 : Empty cell
// 1 : Cell have fresh oranges
// 2 : Cell have rotten oranges

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i , int j, int n, int m,vector<vector<int>>&grid,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && visited[i][j] == 0){
        return true;
    }
    return false;
}

int rottenOranges(vector<vector<int>>&grid,int n ,int m){
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>visited(n,vector<int>(m,0));
    
    bool freshOranges = false;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 2){
                q.push(make_pair(make_pair(i,j),0));
                visited[i][j] = 1;
            }
            else if(grid[i][j] == 1){
                freshOranges = true;
            }
        }
    }
    if(!freshOranges) return 0;
    
    int maxi = -1;
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int tm = q.front().second;
        q.pop();
        maxi = max(maxi,tm);
        
        // top
        int x = row - 1;
        int y = col;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y), tm + 1));
            grid[x][y] = 2;
            visited[x][y] = 1;
        }
        // bottom
        x = row + 1;
        y = col;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y), tm + 1));
            grid[x][y] = 2;
            visited[x][y] = 1;
        }
        
        //left
        x = row;
        y = col - 1;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y), tm + 1));
            grid[x][y] = 2;
            visited[x][y] = 1;
        }
        
        //right
        x = row;
        y = col + 1;
        if(isPoss(x,y,n,m,grid,visited)){
            q.push(make_pair(make_pair(x,y), tm + 1));
            grid[x][y] = 2;
            visited[x][y] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                return -1; // Not all oranges can be rotten
            }
        }
    }
    return maxi;
    
}

int main(){
    vector<vector<int>>grid = {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}
    };
    int n = grid.size();
    int m = grid[0].size();
    
    int ans = rottenOranges(grid,n,m);
    cout<<ans<<endl;
    return 0;
}


