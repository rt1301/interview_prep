/****
 * Given two strings X and Y, print the shortest string that 
 * has both X and Y as subsequences. 
 * If multiple shortest supersequence exists, print any one of them.
 ****/
#include<bits/stdc++.h>
using namespace std;
string printScs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else{
                break;
            }
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string s;
    int i=m,j=n;
    while (i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(x[i-1]);
                i--;
            }else{
                s.push_back(y[j-1]);
                j--;
            }
        }
    }

    while (i>0)
    {
        s.push_back(x[i-1]);
        i--;
    }

    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string x,y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();
    cout<<"SCS is "<<printScs(x,y,m,n);
    return 0;
}