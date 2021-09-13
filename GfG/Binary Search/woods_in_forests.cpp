/****
 * Given an integer K and an array, height[] where height[i] denotes 
 * the height of the ith tree in a forest. The task is to make a cut of 
 * height X from the ground such that exactly K unit wood is collected. 
 * If it is not possible, then print -1 else print X.
 ****/
#include<bits/stdc++.h>
using namespace std;

int woodCollected(vector<int>height, int ht){
    int n = height.size();
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        if(height[i]-ht <= 0){
            break;
        }
        sum+=(height[i]-ht);
    }
    return sum;
}

int solve(vector<int>height, int k){
    sort(height.begin(),height.end());
    int l = 0;
    int r = height.back();
    while(l<=r){
        int m = l + (r-l)/2;
        int collected = woodCollected(height,m);
        if(collected == k){
            return m;
        }
        if(collected > k){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return -1;
}

int main(){
    vector<int>v = {1,2,1,2};
    int k = 2;
    cout<<solve(v,k);
    return 0;
}