#include<bits/stdc++.h>
using namespace std;

class Graph{
   public:
   bool isPoss(int i ,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>&visited){
        if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 0 && matrix[i][j] == 1) return true;
        return false;
   }

   void dfs(int i, int j,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&visited){
        visited[i][j] = 1;

        int x = i + 1;
        int y = j;
        if(isPoss(x,y,n,m,matrix,visited)){
            dfs(x,y,n,m,matrix,visited);
        }

        x = i - 1;
        y = j;
        if(isPoss(x,y,n,m,matrix,visited)){
            dfs(x,y,n,m,matrix,visited);
        }

        x = i;
        y = j - 1;
        if(isPoss(x,y,n,m,matrix,visited)){
            dfs(x,y,n,m,matrix,visited);
        }

        x = i;
        y = j + 1;
        if(isPoss(x,y,n,m,matrix,visited)){
            dfs(x,y,n,m,matrix,visited);
        }
        return;

   }
   int closedIslands(vector<vector<int>>& matrix, int n, int m){

        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
           for(int j = 0;j < m;j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(matrix[i] == 1 && visited[i][j] == 0){
                        dfs(i,j,n,m,matrix,visited);
                    }
                }
                
           }
        }

        int count = 0; 
        for(int i = 0;i < n;i++){
          for(int j = 0;j < m;j++){
                if(matrix[i] == 1 && visited[i][j] == 0){
                    count++;
                    dfs(i,j,n,m,matrix,visited);
                }
           }
        }

        return count;

   }
};
int main(){

   vector<vector<int>>matrix =
          {{0, 0, 0, 0, 0, 0, 0, 1},
           {0, 1, 1, 1, 1, 0, 0, 1},
           {0, 1, 0, 1, 0, 0, 0, 1},
           {0, 1, 1, 1, 1, 0, 1, 0},
           {1, 0, 0, 0, 0, 1, 0, 1}};
   int n = matrix.size();
   int m = matrix[0].size();
   Graph obj;
   int ans = obj.closedIslands(matrix,n,m);
   cout<<ans;
}
