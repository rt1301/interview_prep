#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>graph = vector<vector<int>>(5000);
    vector<int>indegree;
    void addEdge(int u, int v){
        graph[u].push_back(v);
        indegree[v]++;
    }
    bool helper(int n){
        queue<int>q;
        int done = 0;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                done++;
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it:graph[x]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    done++;
                }
            }
        }
        if(done == n){
            return true;
        }else{
            return false;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& adj) {
        indegree = vector<int>(5000,0);
        for(auto a:adj){
            addEdge(a[0],a[1]);
        }
       return helper(numCourses);
    }
};