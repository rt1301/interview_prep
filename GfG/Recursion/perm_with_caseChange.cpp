/****
 * Print all permutations of a string keeping the sequence but changing cases.
 ****/
#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op){
    if(ip.empty()){
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op;
    
    op1.push_back(ip[0]);
    if(isupper(ip[0])){
        op2.push_back(tolower(ip[0]));
    }else if(islower(ip[0])){
        op2.push_back(toupper(ip[0]));
    }

    ip.erase(ip.begin());

    solve(ip,op1);
    solve(ip,op2);
}

int main(){
    string s;
    cin>>s;
    string op = "";
    solve(s,op);
    return 0;
}