#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<int>>v;
    for (size_t i = 0; i < n; i++)
    {
        int start,end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    int take = 1; // activities selected
    int end = v[0][1]; // first activity end time
    for(int i=1;i<n;i++){
        // take the activity only if
        // start of curr actv is more than end time of 
        // previous activity
        if(v[i][0]>=end){
            take++;
            end = v[i][1];
        }
    }
    cout<<take;
    return 0;
}