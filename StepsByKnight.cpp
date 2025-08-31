// Given a square chessboard of size (n x n), the initial position and target postion of Knight are given. 
// Find out the minimum steps a Knight will take to reach the target position.
// Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

// Examples:
// Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
// Output: 1
// Explanation:
// Knight takes 1 step to reach from 
// (3, 3) to (1 ,2).

// Input: n = 6, knightPos[] = [4, 5],targetPos[] = [1, 1]
// Output: 3
// Explanation:
// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) return true;
    return false;
}
int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
    int m = n;
    vector<vector<int>>visited(n,vector<int>(n,0));
    queue<pair<pair<int,int>,int>>q;
    int i = knightPos[0] - 1;
    int j = knightPos[1] - 1;
    
    int tx = targetPos[0] - 1;
    int ty = targetPos[1] - 1;
    q.push(make_pair(make_pair(i,j),0));
    visited[i][j] = 1;
    int mini = INT_MAX;
    
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        
        q.pop();
        
        if(row == tx && col == ty){
            return dist;
        }
        
        // horse moves in chess 8 direction 2.5 steps
        int x = row - 2;
        int y = col + 1;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row - 2;
        y = col - 1;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row + 2;
        y = col - 1;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row + 2;
        y = col + 1;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row + 1;
        y = col + 2;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row + 1;
        y = col - 2;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row - 1;
        y = col - 2;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
        
        x = row - 1;
        y = col + 2;
        if(isPoss(x,y,n,m,visited)){
            q.push(make_pair(make_pair(x,y),dist + 1));
            visited[x][y] = 1;
        }
    }
    
    return -1;
    
}

int main(){
    vector<int>knightLocation = {4,5};
    vector<int>targetLocation = {1,1};
    int n = 6;
    int ans = minStepToReachTarget(knightLocation,targetLocation,n);
    cout<<ans;
    return 0;
}