// Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a 
// hospital is in the form of a 2-D matrix.
// Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following 
// meaning:
// 0: Empty ward
// 1: Cells have uninfected patients
// 2: Cells have infected patients
// An infected patient at ward [i,j] can infect other uninfected patient at indexes 
// [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
// Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e 
// all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

// Example 1:
// Input:
// 3 5
// 2 1 0 2 1
// 1 0 1 2 1
// 1 0 0 2 1 
// Output:
// 2
// Explanation:
// Patients at positions {0,0}, {0, 3}, {1, 3}
// and {2, 3} will infect patient at {0, 1}, 
// {1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
// unit time. And, during 2nd unit time, patient at 
// {1, 0} will get infected and will infect patient 
// at {2, 0}. Hence, total 2 unit of time is
// required to infect all patients.

// Example 2:
// Input:
// 3 5
// 2 1 0 2 1
// 0 0 1 2 1
// 1 0 0 2 1
// Output:
// -1
// Explanation:
// All patients will not be infected.

#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m,vector<vector<int>>&hospital){
    if(i >= 0 && i < n && j >= 0 && j < m && hospital[i][j] == 1) return true;
    return false;
}
int helpaterp(vector<vector<int>> hospital) {
    // code here
    int n = hospital.size();
    int m = hospital[0].size();
    queue<pair<pair<int,int>,int>>q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(hospital[i][j] == 2) q.push(make_pair(make_pair(i,j),0));
        }
    }
    
    int maxi = -1;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int tm = q.front().second;
        
        q.pop();
        maxi = max(maxi,tm);
        
        //north
        int x = row - 1;
        int y = col;
        if(isPoss(x,y,n,m,hospital)){
            q.push(make_pair(make_pair(x,y),tm+1));
            hospital[x][y] = 2;
        }
        //south
        x = row + 1;
        y = col;
        if(isPoss(x,y,n,m,hospital)){
            q.push(make_pair(make_pair(x,y),tm+1));
            hospital[x][y] = 2;
        }
        //east
        x = row;
        y = col + 1;
        if(isPoss(x,y,n,m,hospital)){
            q.push(make_pair(make_pair(x,y),tm+1));
            hospital[x][y] = 2;
        }
        
        //west
        x = row;
        y = col - 1;
        if(isPoss(x,y,n,m,hospital)){
            q.push(make_pair(make_pair(x,y),tm+1));
            hospital[x][y] = 2;
        }
        
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(hospital[i][j] == 1) return -1;
        }
    }
    
    return maxi == -1 ? 0 : maxi;
}

int main(){
    vector<vector<int>>arr = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    int ans = helpaterp(arr);
    cout<<ans;
    return 0;
}