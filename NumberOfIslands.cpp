// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of 
// operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which 
// means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] 
// means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are 
// there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

// Example 1:
// Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}
// Output: 1 1 2 2

// Example 2:
// Input: n = 4
// m = 5
// k = 4
// A = {{0,0},{1,1},{2,2},{3,3}}
// Output: 1 2 3 4

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1 && visited[i][j] == 0)return true;
    return false;
}
void dfs(int i,int j,int n,int m,vector<vector<int>>&visited,vector<vector<int>>&mat){
    visited[i][j] = 1;
    
    //north
    int x = i - 1;
    int y = j;
    if(isPoss(x,y,n,m,mat,visited)){
        dfs(x,y,n,m,visited,mat);
    }
    
    //south
    x = i + 1;
    y = j;
    if(isPoss(x,y,n,m,mat,visited)){
        dfs(x,y,n,m,visited,mat);
    }
    
    //east
    x = i;
    y = j + 1;
    if(isPoss(x,y,n,m,mat,visited)){
        dfs(x,y,n,m,visited,mat);
    }
    //west
    x = i;
    y = j - 1;
    if(isPoss(x,y,n,m,mat,visited)){
        dfs(x,y,n,m,visited,mat);
    }
    return;
}
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector<vector<int>>mat(n,vector<int>(m,0));
    vector<int>ans;
    int k = operators.size();
    if(k == 0) return {};
    
    int idx = 1;
    for(vector<int>res:operators){
        int i = res[0];
        int j = res[1];
        mat[i][j] = 1;
        if(idx == 1){
            ans.push_back(1);
            idx++;
            continue;
        } 
        
        int count = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int k = 0;k < n;k++){
            for(int l = 0;l < m;l++){
                if(mat[k][l] == 1 && !visited[k][l]){
                    dfs(k,l,n,m,visited,mat);
                    count++;
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    vector<vector<int>>arr = {
        {1,1},{0,1},{3,3},{3,4}
    };
    int n = 4;
    int m = 5;
    vector<int>ans = numOfIslands(n,m,arr);
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}