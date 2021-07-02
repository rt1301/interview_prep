#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for (size_t i = 0; i < n; i++)
    {
        minHeap.push(v[i]);
    }
    int ans = 0;
    while (minHeap.size()>1)
    {
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();
        ans+=e1+e2;
        minHeap.push(e1+e2);
    }
    
    cout<<ans;
    return 0;
}