// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. 
// However, you cannot enter a locked room without having its key.
// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, 
// and you can take all of them with you to unlock the other rooms.
// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
// return true if you can visit all the rooms, or false otherwise.

// Example 1:
// Input: rooms = [[1],[2],[3],[]]
// Output: true
// Explanation: 
// We visit room 0 and pick up key 1.
// We then visit room 1 and pick up key 2.
// We then visit room 2 and pick up key 3.
// We then visit room 3.
// Since we were able to visit every room, we return true.

// Example 2:
// Input: rooms = [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 
// idea -> adjacency  0->{1,3}  1->{0,1,3}  2->{2}  3->{0}
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&visited,vector<vector<int>>& rooms){
    visited[node] = 1;

    for(auto neigh:rooms[node]){
        if(!visited[neigh]){
            dfs(neigh,visited,rooms);
        }
    }
    return ;
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    int m = rooms[0].size();
    vector<int>visited(n,0);
    dfs(0,visited,rooms);
    for(int i = 1;i < n;i++){
        if(visited[i] == 0) return false;
    }
    return true;
}
int main(){
    vector<vector<int>>arr = {
        {1,3},{3,0,1},{2},{0}
    };
    bool ans = canVisitAllRooms(arr);
    cout<<ans;
    return 0;
}