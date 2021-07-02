#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>components;
int get_cmp(int src){
    if(vis[src]){
        return 0;
    }
    vis[src] = true;
    int ans = 1;
    for(auto i:adj[src]){
        if(!vis[i]){
            ans+=get_cmp(i);
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            components.push_back(get_cmp(i));
        }
    }
    // cout<<"Components are\n";
    // for(auto it:components){
    //     cout<<it<<" ";
    // }
    // Question regarding selection from a group of friends
    // After finding out sizes of individual components
    // At the ith component, choose one person from that component
    // and choose the other person from rest of the group
    long long ans = 0;
    for(auto i:components){
        ans+=(i*(n-i));
    }
    cout<<(ans/2);
    return 0;
}