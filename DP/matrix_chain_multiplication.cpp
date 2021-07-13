/****
 * Given a sequence of matrices, find the most efficient way to multiply 
 * these matrices together. The problem is not actually to perform the 
 * multiplications, but merely to decide in which order to perform the multiplications.
 * Problem Statement - https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
 ****/
#include<bits/stdc++.h>
using namespace std;
// Approach 1 - Recursive Solution
// Step1 - choose appropriate values of i and j
int mcmRecursive(int arr[], int i, int j){
    // Step 2 - Find Base Condition
    // if only single or zero element left return 0
    if(i>=j){
        return 0;
    }
    // Step 3 - Find K loop Scheme
    // k = i, k = j-1 (left and right end vals for k)
    // Partition - i to k && k+1 to j
    int minAns = INT_MAX;
    for(int k = i; k<j;k++){
        // Step 4 - Calculate answer from temp answer
        // First part + Second Part + Cost of multiplying both parts
        int temp = mcmRecursive(arr,i,k) + mcmRecursive(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        minAns = min(minAns, temp);
    }

    return minAns;
}
// Memoization Approach
int dp[1001][1001];
int mcm(int arr[], int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i>=j){
        return 0;
    }
    int mnAns = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mnAns = min(mnAns, temp);
    }
    return dp[i][j] = mnAns;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            dp[i][j] = -1;
        }
    }
    cout << "Minimum number of multiplications is "
         <<mcm(arr,1,n-1);
    return 0;
}