/****
 * Minimum Spanning Tree using Kruskal Algorithm
 ****/
#include<bits/stdc++.h>
using namespace std;
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
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a]+=sz[b];
    }
}
int main(){
    // Creating Disjoint Sets
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    // Sort edges according to increasing weight
    sort(edges.begin(),edges.end());
    // Kruskal Algo
    int cost = 0;
    cout<<"Selected Edges\n";
    for(auto i:edges){
        int u = i[1];
        int v = i[2];
        int w = i[0];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            continue;
        }else{
            cout<<"Edge: "<<u<<" "<<v<<endl;
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<"Cost of MST is: "<<cost<<endl;
    return 0;
}
