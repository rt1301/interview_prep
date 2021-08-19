/****
 * Giving a dictionary and a string ‘str’, find the 
 * longest string in dictionary which can be formed by 
 * deleting some characters of the given ‘str’. 
 ****/
#include<bits/stdc++.h>
using namespace std;
bool isSubseq(string s1,string s2){
    int n = s1.length(),m=s2.length();
    int j=0;
    for(int i=0;j<n && i<m; i++){
        if(s1[j] == s2[i]){
            j++;
        }
    }
    if(j == m){
        return true;
    }
    return false;
}
string solve(string s, vector<string>v){
    int n = s.length();
    int len = 0;
    string res = "";

    for(int i=0;i<v.size();i++)
    {
        if(len<v[i].size() && isSubseq(s,v[i])){
            res = v[i];
            len = v[i].size();
        }
    }

    return res;
}

int main(){
    vector<string> dict = {"ale", "apple", "monkey", "plea"};
    string str = "abpcplea";
    cout<<solve(str,dict);
    return 0;
}