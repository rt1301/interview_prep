#include<bits/stdc++.h>
using namespace std;

void solve(string s, string op, int n){
    if(n == 0){
        cout<<op<<endl;
        return;
    }
    if(s[n-1] == '?'){
        string op1,op2;
        op1=op,op2=op;
        op1.push_back('1');
        op2.push_back('0');
        solve(s,op1,n-1);
        solve(s,op2,n-1);
    }
    else{
        string op1;
        op1 = op;
        op1.push_back(s[n-1]);
        solve(s,op1,n-1);
    }
}

int main(){
    string s;
    cin>>s;
    string op="";
    solve(s,op,s.size());
    return 0;
}