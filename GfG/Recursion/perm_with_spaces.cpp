/****
 * Given a string you need to print all possible strings that can 
 * be made by placing spaces (zero or one) in between them. 
 * The output should be printed in sorted increasing order of strings
 ****/
#include<bits/stdc++.h>
using namespace std;
void solve(string ip,string op){
    if(ip.length() == 1){
        op.push_back(ip[0]);
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(ip[0]);
    op1.push_back(' ');

    op2.push_back(ip[0]);

    ip.erase(ip.begin());

    solve(ip,op1);
    solve(ip,op2);
}

int main(){
    string ip;
    cin>>ip;
    string op = "";
    if(ip.length() == 0){
        cout<<"Invalid String\n";
    }else{
        solve(ip,op);
    }
    return 0;
}