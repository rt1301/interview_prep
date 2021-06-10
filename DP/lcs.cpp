/****
 * Given two strings of length m and n respectively.
 * Find the length of the longest common subsequence of the strings
 ****/
#include<bits/stdc++.h>
using namespace std;

int lcs(int memo[100][100],int m,int n,string s1,string s2)
{
    if(memo[m][n] != -1){
        return memo[m][n];
    }
    if(m == 0 || n == 0){
        memo[m][n] = 0;
    }
    else{
        if(s1[m-1] == s2[n-1]){
            memo[m][n] = 1+ lcs(memo,m-1,n-1,s1,s2);
        }else{
            memo[m][n] = max(lcs(memo,m,n-1,s1,s2),lcs(memo,m-1,n,s1,s2));
        }
    }
    return memo[m][n];
}

int main(){
    string s1="ABCDGH";
    string s2="AEDFHR";
    int m = s1.length();
    int n = s2.length();
    int memo[100][100];
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            memo[i][j] = -1;
        }
        
    }
    cout<<lcs(memo,m,n,s1,s2);
    return 0;
}