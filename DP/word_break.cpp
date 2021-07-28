#include<bits/stdc++.h>
using namespace std;
int dp[100000];
bool dictionaryFind(string s){
    set<string>st = {"i","like","sam","sung","samsung","mobile","ice","cream","icecream","man","go","mango"};
    // set<string>st = {"dog","s","gs"};
    if(st.find(s) != st.end()) return true;
    return false;
}

bool wordBreak(string s){
    int n = s.length();
    if(dp[s.length()] != -1) return dp[s.length()];
    if(n == 0) return true;
    for(int i=1;i<=n;i++){
        bool temp = dictionaryFind(s.substr(0,i)) && wordBreak(s.substr(i,n-1));
        if(temp) return dp[i] = 1;
    }
    return dp[s.length()] = 0;
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s;
    cin>>s;
    if(wordBreak(s)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}