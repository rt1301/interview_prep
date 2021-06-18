// Given a stair of n steps
// A person can hop either 1,2 or 3 steps at a time
// Find the different number of combinations
#include<bits/stdc++.h>
using namespace std;
// O(3^n) time complexity
int numOfSteps(int n){
    if(n <0) return 0;
    else if (n == 0) return 1;
    else{
        int res = numOfSteps(n-1) + numOfSteps(n-2) + numOfSteps(n-3);
        return res;
    }
}
// DP Solution
int tripleStepHelper(int i, int memo[],int n){
    if(i<0) return 0;
    if(i==0) return 1;
    else if(memo[i]>-1){
        return memo[i];
    }else{
        memo[i] = tripleStepHelper(i-1,memo,n) + tripleStepHelper(i-2,memo,n) + tripleStepHelper(i-3,memo,n);
        return memo[i];
    }
}
int tripleStep(int n){
    int memo[n+1];
    for(int i=0;i<=n;i++)memo[i]=-1;
    return tripleStepHelper(n,memo,n+1);
}
int main(){
    cout<<tripleStep(5);
    return 0;
}