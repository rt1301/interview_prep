#include<bits/stdc++.h>
using namespace std;
string removeDupl(string s){
    string ans;
    for(char c:s){
        if(ans.size() && ans.back()==c){
            ans.pop_back();
        }else{
            ans.push_back(c);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<removeDupl(s);
    return 0;
}