/****
 * An Array of integers is given, both +ve and -ve. 
 * You need to find the two elements such that their sum is closest to zero.
 ****/

#include<bits/stdc++.h>
using namespace std;
pair<int,int>twoSum(vector<int>v){
    sort(v.begin(),v.end());
    int l = 0;
    int r = v.size()-1;
    int sum = 0;
    int min_sum = INT_MAX;
    int min_l = 0;
    int min_r = v.size()-1;
    while(l<r){
        sum = v[l] + v[r];
        if(abs(sum)<abs(min_sum)){
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if(sum<0) l++;
        else r--; 
    }
    return {v[min_l],v[min_r]};
}
int main(){
    vector<int>arr = {1, 60, -10, 70, -80, 85};
    pair<int,int>ans = twoSum(arr);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}