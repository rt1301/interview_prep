#include<bits/stdc++.h>
using namespace std;

vector<int>prefix(string s){
    int n = s.length();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j])
        {
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main(){
    // S - Pattern
    string s;
    cin>>s;
    vector<int>pre = prefix(s);
    // T - Actual String
    string t;
    cin>>t;
    int pos= -1;
    int j=0,i=0;
    int n = t.length();
    while (i<n)
    {
        if(s[j] == t[i]){
            i++;
            j++;
        }else{
            if(j!=0){
                j = pre[j-1];
            }
            else{
                i++;
            }
        }
        if(j == s.size()){
            pos = i - s.size();
            break;
        }
    }
    cout<<pos;
    return 0;
}