#include<bits/stdc++.h>
using namespace std;
string revString(string s){
    int n = s.length();
    vector<string>words;
    for(int i=0;i<n;i++){
        string temp;
        while (i<n && s[i] != ' ')
        {
            temp.push_back(s[i]);
            i++;
        }
        words.push_back(temp);
    }
    string ans = "";
    for(int i=words.size()-1;i>=0;i--){
        ans+=words[i];
        ans.push_back(' ');
    }
    return ans;
}

int main(){
    string s = "i like programming very much";
    cout<<revString(s)<<endl;
    return 0;
}