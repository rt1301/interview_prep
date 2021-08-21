#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int>ans(N,0);
vector<int>flag(N,0);
void minimumTime(vector<bool>&hasApple,int u, int par, vector<vector<int>>adj){
    if(hasApple[u] == true){
        flag[u] = 1;
    }
    for(auto it:adj[u]){
        if(it != par){
            minimumTime(hasApple,it,u,adj);
            if(flag[it] > 0){
                ans[u]+=(ans[it]+2);
            }
            flag[u]|=flag[it];
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> hasApple{false, false,
                          true, false,
                          true, true,
                          false};
    minimumTime(hasApple,0,-1,adj);
    cout<<ans[0];
    return 0;
}