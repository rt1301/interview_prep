#include<bits/stdc++.h>
using namespace std;

int solution(int f, int e){
    int dp[f+1][e+1]; // dp table
    // Fill out the base conditions
    // res(f,1) = f
    // res(1,e) = 1
    // res(0,e) = 0
    for(int i=1;i<=e;i++){
        dp[0][i] = 0; // no floors present
        dp[1][i] = 1; // only 1 floor is present
    }
    for(int i=2;i<=f;i++){
        dp[i][1] = i;
    }
    // Fill the dp array using the foll. recursive relation
    // res(f,e) = Min(1<=x<=f)(max(res(f-1,e-1),res(f-x,e)) + 1)
    for(int i=2;i<=f;i++){
        for(int j=2;j<=e;j++){
            dp[i][j] = INT_MAX;
            for(int x=1;x<=i;x++){
                dp[i][j] = min(dp[i][j],1 + max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
}

int main(){
    int f = 36;
    int e = 2;
    cout<<solution(f,e);
    return 0;
}