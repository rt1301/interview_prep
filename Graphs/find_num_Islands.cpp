/****
 * Given a boolean 2D matrix, find the number of islands. 
 * A group of connected 1s forms an island.
 * This is a variation of Finding Number of Components in a directed Graph
 * Problem Statement - https://www.geeksforgeeks.org/find-number-of-islands/
 ****/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;
int get_component(int x){
    if(vis[x]) return 0;
    vis[x] = 1;
    int ans = 1;
    for(int i=0;i<adj[x].size();i++){
        if(!vis[i] && adj[x][i] == 1){
            ans+=get_component(i);
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    adj = vector<vector<int>>(n+1,vector<int>(m+1,0));
    vis = vector<bool>(n+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    vector<int>cmp;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cmp.push_back(get_component(i));
        }
    }
    cout<<"The Number of Islands are: "<<cmp[0];
    return 0;
}