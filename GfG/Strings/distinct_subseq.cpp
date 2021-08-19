#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    int n = s.length();
    vector<int>last(256,-1);
    int dp[n+1];
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        dp[i] = 2*dp[i-1];

        if(last[s[i-1]]!= -1){
            dp[i] -= dp[last[s[i - 1]]];
        }

        last[s[i-1]] = i-1;
    }

    return dp[n];
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}