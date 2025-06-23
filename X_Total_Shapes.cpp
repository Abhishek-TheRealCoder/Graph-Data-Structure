
#include<bits/stdc++.h>
using namespace std;    


class Graph {
public:   

    bool isPoss(int i ,int j,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&visited){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 'X' && visited[i][j] == 0) return true;
        return false;
    }

    void dfs(int i,int j,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[i][j] = 1;

        //north
        int x = i - 1;
        int y = j;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        //south
        x = i + 1;
        y = j;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        //east
        x = i;
        y = j + 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }
        //west
        x = i;
        y = j - 1;
        if(isPoss(x,y,n,m,grid,visited)){
            dfs(x,y,n,m,grid,visited);
        }

        return ;   
    }
    int xShape(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 'X' && visited[i][j] == 0){
                    dfs(i,j,n,m,grid,visited);
                    count++;
                }
            }
        }    
        return count;  

    }

};

int main(){

    vector<vector<char>>grid = {
        {'X','O','X'},
        {'O','X','O'},
        {'X','X','X'}
    };

    Graph obj;
    int ans = obj.xShape(grid);
    cout<<ans<<endl;
    return 0;
}