#include<bits/stdc++.h>
using namespace std;
// Global Variables
int N = 1e+5;
vector<int>parent(N);
vector<int>sz(N);
void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a]+=sz[b];
    }
}
int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    // Make a graph and check for a Cycle
    int n,m;cin>>n>>m;
    vector<vector<int>>edges; // store different edges
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    bool cycle = false;
    for(auto i:edges){
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            cycle = true;
            break;
        }else{
            union_set(u,v);
        }
    }
    if(cycle){
        cout<<"Cycle Exists";
    }
    else{
        cout<<"Cycle Doesn't exists";
    }

    return 0;
}