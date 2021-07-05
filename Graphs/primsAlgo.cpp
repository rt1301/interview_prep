/****
 * Minimum Spanning Tree using Kruskal Algorithm
 ****/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int N = 1e+5;
vector<vector<vector<int>>>graph(N);
vector<int>dist(N);
vector<int>parent(N);
vector<bool>vis(N,0);
int cost = 0;
const int INF = 1e9;
void primsMST(int src){
    for(int i=0;i<n;i++){
        dist[i] = INF; 
    }
    dist[src] = 0;
    set<vector<int>>s;
    s.insert({0,src});
    cout<<"Selected Edges\n";
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cost+=w;
        cout<<"Edge: "<<u<<" "<<v<<endl;
        for(auto i: graph[x[1]]){
            if(vis[i[0]]){
                continue;
            }
            if(dist[i[0]]>i[1]){
                s.erase({dist[i[0]],i[0]});
                dist[i[0]] = i[1];
                s.insert({dist[i[0]],i[0]});
                parent[i[0]] = x[1];
            }
        }
    }
    
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>v1 = {v,w};
        vector<int>v2 = {u,w};
        graph[u].push_back(v1);
        graph[v].push_back(v2);
    }
    primsMST(0);
    cout<<cost<<endl;
    return 0;
}