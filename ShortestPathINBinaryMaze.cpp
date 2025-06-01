

#include<bits/stdc++.h>
using namespace std;

int shortestPathInBinaryMaze(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination){
    int n = grid.size();
    int m = grid[0].size();
    int startRow = source.first;
    int startCol = source.second;

    vector<vector<int>>visited(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(startRow,startCol),0));

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
    }
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