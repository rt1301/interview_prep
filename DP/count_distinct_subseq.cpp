/****
 * Given a string, find the count of distinct subsequences of it. 
 ****/
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;

int countSub(string s){
    // used to store last occurrence of any character
    vector<int>last(MAX_CHAR,-1);

    int n = s.length();
    // dp[i] = Distinct Subsequences of length i
    int dp[n+1];

    dp[0] = 1; //empty string will only have 1 subsequence

    for(int i=1;i<=n;i++){
        // No. of subsequences with substrings [0...i-1];
        dp[i] = 2*dp[i-1];
        // if current character has already occurred
        // Delete previous subseq ending with that character
        if(last[s[i-1]] != -1){
            dp[i]-=dp[last[s[i-1]]]; //last[s[i-1]] denotes repetition
        }

        last[s[i-1]] = (i-1);
    }
    cout<<dp[6]<<endl;
    return dp[n];
}

int main(){
    string s;
    cin>>s;
    cout<<"Distinct Subsequences are: "<<countSub(s);
    return 0;
}