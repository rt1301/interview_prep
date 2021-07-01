#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>color;
bool bipart = true;
void colorNode(int src, int curr){
    if(color[src] != -1 && color[src] != curr){
        bipart = false;
        return;
    }
    color[src] = curr;
    if(vis[src]){
        return;
    }
    vis[src] = true;
    for(auto i:adj[src]){
        // if curr node is 1 color neighbour as 0
        // and vice versa
        colorNode(i,curr xor 1);
    }
}
int main(){
    bipart = true;
    int n,m;
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,0);
    color = vector<int>(n,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            colorNode(i,0);
        }
    }
    if(bipart){
        cout<<"Graph is bipart";
    }else{
        cout<<"Graph is non bipart";
    }
    return 0;
}