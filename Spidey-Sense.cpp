#include<bits/stdc++.h>
using namespace std;


class Graph{
   public:
    bool isPoss(int i,int j,int n,int m,vector<vector<char>>&matrix,vector<vector<int>>&dist){
        if(i >= 0 && i < n && j >= 0 && j < m && matrix[i][j] !='B' && matrix[i][j] !='W' && dist[i][j] == 0) return true;
        return false;
    }

    vector<vector<int>> findDistance(vector<vector<char> >& matrix, int m,int n) {
        vector<vector<int>>distance(m,vector<int>(n,0));
        //<<row,col>,dist>
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 'B'){
                    q.push(make_pair(make_pair(i,j),0));
                }     
           }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            //north
            int x = row - 1;
            int y = col;
            if(isPoss(x,y,m,n,matrix,distance)){
                distance[x][y] = dist + 1;
                q.push(make_pair(make_pair(x,y),dist + 1));
            }

            x = row + 1;
            y = col;
            if(isPoss(x,y,m,n,matrix,distance)){
                distance[x][y] = dist + 1;
                q.push(make_pair(make_pair(x,y),dist + 1));
            }

            x = row;
            y = col - 1;
            if(isPoss(x,y,m,n,matrix,distance)){
                distance[x][y] = dist + 1;
                q.push(make_pair(make_pair(x,y),dist + 1));
            }

            x = row;
            y = col + 1;
            if(isPoss(x,y,m,n,matrix,distance)){
                distance[x][y] = dist + 1;
                q.push(make_pair(make_pair(x,y),dist + 1));
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n; j++){
                if(matrix[i][j] == 'W'){
                    distance[i][j] = -1; 
                }else if(matrix[i][j] == 'O' && distance[i][j] == 0){
                    distance[i][j] = -1;   
                }
            }
        }
        return distance;
    }
 };
 int main(){ 
  vector<vector<char>>matrix = {
	{'W','B','W','B','O','O','O','W','B'},
    {'O','B','O','O','O','B','O','W','O'},
    {'B','B','B','W','B','B','B','O','B'},
    {'B','O','O','W','B','O','B','W','W'},
    {'B','B','W','O','B','B','B','W','O'}
  };
  int n = matrix.size();
  int m = matrix[0].size();
  Graph obj;
  vector<vector<int>>ans = obj.findDistance(matrix,n,m);

  for(vector<int>res:ans){
    for(auto x : res){
       cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}
