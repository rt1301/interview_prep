#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>a(n); // stop and their fuel data
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int l,p;
    cin>>l>>p;
    for(int i=0;i<n;i++){
        a[i].first = l-a[i].first;
    }
    sort(a.begin(),a.end());
    int ans = 0;
    int curr = p;
    bool flag = false;
    priority_queue<int,vector<int>>maxHeap;
    for(int i=0;i<n;i++){
        if(curr>=l){
            break;
        }
        while (curr<a[i].first)
        {
            if(maxHeap.empty()){
                flag = true;
                break;
            }
            ans++;
            curr+=maxHeap.top();
            maxHeap.pop();
        }
        if(flag){
            break;
        }
        maxHeap.push(a[i].second);
    }
    if(flag){
        cout<<-1<<endl;
    }else{
        while (!maxHeap.empty() && curr<l)
        {
            ans++;
            curr+=maxHeap.top();
            maxHeap.pop();
        }
        if(curr<l){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}