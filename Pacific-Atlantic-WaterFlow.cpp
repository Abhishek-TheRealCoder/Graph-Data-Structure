
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    bool isPoss(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<int>>&visited,int prev_i,int prev_j){
        if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 0 && mat[i][j] >= mat[prev_i][prev_j]) return true;
        return false;
    }

    void dfs(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<int>>&visited){
        visited[i][j] = 1;
        
        //north
        int x = i - 1;
        int y = j;
        if(isPoss(x,y,n,m,mat,visited,i,j)){
            dfs(x,y,n,m,mat,visited);
        }

        //south
        x = i + 1;
        y = j;
        if(isPoss(x,y,n,m,mat,visited,i,j)){
            dfs(x,y,n,m,mat,visited);
        }

        //west
        x = i;
        y = j - 1;
        if(isPoss(x,y,n,m,mat,visited,i,j)){
            dfs(x,y,n,m,mat,visited);
        }

        //east
        x = i;
        y = j + 1;
        if(isPoss(x,y,n,m,mat,visited,i,j)){
            dfs(x,y,n,m,mat,visited);
        }

        return ;
    }

    
    int countCoordinates(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited1(n, vector<int>(m, 0));
        vector<vector<int>>visited2(n, vector<int>(m, 0));

        //for pacific ocean
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i == 0 || j == 0){
                    dfs(i,j,n,m,mat,visited1);
                }
            }
        }
        //for atlantic ocean
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i == n-1 || j == m-1){
                    dfs(i,j,n,m,mat,visited2);
                }
            }
        }

        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(visited1[i][j] == 1 && visited1[i][j] == visited2[i][j]){
                    count++;
                }
            }
        }

        return count;
        
    }
};
int main(){
    vector<vector<int>>mat = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    
    Graph obj;
    int result = obj.countCoordinates(mat);
    cout << "Number of coordinates: " << result << endl;
    return 0;
}
