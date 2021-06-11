#include<bits/stdc++.h>
using namespace std;

int subseq(int arr[],int n){
    int dp[n];
    dp[0] = 1;  // first element in the arr will be subsequence
                // of length 1
    for(int i=1;i<n;i++){
        dp[i] = 1; // atleast a subsequence of length 1
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){ // if arr[j] is smaller then arr[i] can be appended in front of it
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp,dp+n);
}
// Using Binary Search O(nlogn) time
int ceilIdx(vector<int>v,int x){
    int r = v.size()-1;
    int l = 0;
    int m;
    while(r>l){
        m = l + (r-l)/2;
        if(v[m]>=x){
            r = m;
        }else{
            l = m+1;
        }
    }
    return r;
}
int lis(int arr[], int n){
    vector<int>tail;
    int len = 1;
    tail.push_back(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]>tail[len-1]){ //current element in arr is greater
            tail.push_back(arr[i]);
            len++;
        }else{
            // current element in arr is smaller
            int c = ceilIdx(tail,arr[i]);
            tail[c] = arr[i];
        }
    }
    return tail.size();
}
int main(){
    int arr[] = {4,10,2,3,2,3,6,5,8,11,2,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lis(arr,n);
    return 0;
}