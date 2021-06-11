#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++) dp[i][0] = i; //filling the base condition when string 1 is empty
    for(int j=1;j<=n;j++) dp[0][j] = j; // when string 2 is empty

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]) // last characters match in the string
            {
                dp[i][j] = dp[i-1][j-1]; // insert the diagonal element
            }else{ // last characters don't match
                dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}
int main(){
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    cout<<editDistance(s1,s2,s1.length(),s2.length());
    return 0;
}