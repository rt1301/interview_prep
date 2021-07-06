#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(string ip, string op, vector<string>&v){
        if(ip.empty()){
            v.push_back(op);
            return;
        }
        if((ip[0] - '0')>=0 && (ip[0] - '0')<=9){
            string opdigit = op;
            opdigit.push_back(ip[0]);
            ip.erase(ip.begin());
            solve(ip,opdigit,v);
        }else{
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin());
            solve(ip,op1,v);
            solve(ip,op2,v);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>v;
        string op = "";
        solve(s,op,v);
        return v;
    }
};