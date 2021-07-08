/****
 * Minimum number of deletions and insertions to transform one string into 
 * another Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
 * The task is to remove/delete and insert minimum number of characters 
 * from/in str1 so as to transform it into str2. It could be possible 
 * that the same character needs to be removed/deleted from one point of 
 * str1 and inserted to some another point.
 ****/
#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j] = 0;
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

    return dp[m][n];
}

int main(){
    string x,y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();
    int l = lcs(x,y,m,n);
    int deletions = m-l;
    int insertions = n-l;
    cout<<"Deletion: "<<deletions<<"\nInsertions: "<<insertions;
    return 0;
}