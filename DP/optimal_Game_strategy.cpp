#include<bits/stdc++.h>
using namespace std;

int solution(int arr[],int n){
    int dp[n][n]; 
    // dp[i][j] = maximum of value of the coin selected
    for(int i=0;i<n-1;i++){
        // base case arises when i+1 == j
        dp[i][i+1] = max(arr[i],arr[i+1]);
    }
    // column for dp table changes at gap of 2
    for(int gap = 3; gap<n; gap+=2){
        for(int i=0;i+gap<n;i++){
            int j = i + gap; // column number in dp table
            dp[i][j] = max(arr[i]+min(dp[i+1][j-1],dp[i+2][j]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}


int main(){
    int arr[] = {20,5,4,6,8,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<solution(arr,size);
    return 0;
}