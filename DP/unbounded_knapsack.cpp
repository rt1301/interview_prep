/****
 * Given a knapsack weight W and a set of n items with 
 * certain value vali and weight wti, 
 * we need to calculate the maximum amount that could make up this quantity exactly.
 ****/
#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int val[], int wt[], int n, int W){
    int t[n+1][W+1];
    for(int i=0;i<=W;i++){
        t[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        t[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            // If given weight is less than weight of 
            // knapsack
            if(wt[i-1]<=j){
                // you can take an item as many times as you want
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];
}

int main(){
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
 
    cout << unboundedKnapsack(val,wt,n,W);
    return 0;
}