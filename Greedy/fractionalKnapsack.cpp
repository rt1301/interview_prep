#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    double vw1, vw2;
    vw1 = (double)p1.first/p1.second;
    vw2 = (double)p2.first/p2.second;
    return vw1>vw2;
}
int main(){
    int n;cin>>n;
    vector<pair<int,int>>v(n); //list of item with value and weight
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int w; // weight of knapsack
    cin>>w;
    sort(v.begin(),v.end(),compare);
    int ans=0;
    for(int i=0;i<n;i++){
        if(w>=v[i].second){
            ans+=v[i].first;
            w-=v[i].second;
            continue;
        }
        // if weight of knapsack is less than item's wt
        // take fractional weight of item
        double vw =(double)v[i].first/v[i].second;
        ans+=vw*w;
        w=0;
        break;
    }
    cout<<ans<<endl;
    return 0;
}