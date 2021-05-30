#include<bits/stdc++.h>
using namespace std;

string sortChars(string s)
{
    sort(s.begin(), s.end());
    return s;
}
vector<string> groupAnagrams(vector<string>s){
    map<string,vector<string>>m;
    vector<string>ans;
    for(int i=0;i<s.size();i++){
        string key = sortChars(s[i]);
        m[key].push_back(s[i]);
    }
    for(auto it = m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
            ans.push_back(it->second[i]);
        }
    }
    return ans;
}
int main(){
    vector<string> s = {"abcd", "asleep", "notananagram", "cdba", "please", "dcba"};
    cout<<"Before sorting\n";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<"\nAfter Sorting\n";
    s = groupAnagrams(s);
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }

    return 0;
}