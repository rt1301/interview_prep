#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],int n, vector<bool>&vis, int node){
    // Preorder
    vis[node] = 1;
    // cout<<node<<" ";

    // Inorder
    for(auto it=adj[node].begin();it!=adj[node].end();it++){
        
        if(vis[*it]);
        else{
            dfs(adj,n,vis,*it);
        }
    }

    // Postorder
    cout<<node<<" ";
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<bool>visited(n+1,false);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(adj,n,visited,1);
}