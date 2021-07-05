/****
 * Single Source Shortest path from a vertex u to 
 * all the vertices in the graph
 ****/
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>graph(n+1);// weighted graph
    vector<int>dist(n+1,inf);
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    set<pair<int,int>>s;
    // In Set -> {weight, vertex}
    int src;
    cin>>src;
    dist[src] = 0;
    s.insert({0,src});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for(auto it:graph[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    cout<<"Shortest Distances are:\n";
    for(int i=1;i<=n;i++){
        if(dist[i] < inf){
            cout<<dist[i]<<" ";
        }else{
            cout<<-1<<" ";
        }
    }
    return 0;
}