/****
 * Given a string A, we may represent it as a binary tree by partitioning 
 * it to two non-empty substrings recursively.
 ****/
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,bool>mp;
// Recursive Solution
bool solve(string s1, string s2){
    if(s1.compare(s2) == 0){
        return true;
    }
    if(s1.length()<=1){
        return false;
    }
    int n = s1.size();
    bool flag = false;
    for(int k = 1;k<n;k++){
        bool cond1 = solve(s1.substr(0,k),s2.substr(n-k,k)) && solve(s1.substr(k,n-k),s2.substr(0,n-k));
        bool cond2 = solve(s1.substr(0,k),s2.substr(0,k)) && solve(s1.substr(k,n-k),s2.substr(k,n-k));
        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    return flag;
}
// Memoized solution
bool solveMemo(string s1, string s2){
    if(s1.compare(s2) == 0) return true;
    if(s1.length()<=1) return false;

    int n = s1.length();
    string temp = s1;
    temp.push_back(' ');
    temp+=s2;
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    else{
        bool flag = false;
        for(int i=1;i<n;i++){
            bool cond1 = solveMemo(s1.substr(0,i),s2.substr(n-i,i)) && solveMemo(s1.substr(i,n-i),s2.substr(0,n-i));
            bool cond2 = solveMemo(s1.substr(0,i),s2.substr(0,i)) && solveMemo(s1.substr(i,n-i), s2.substr(i,n-i));

            if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        return mp[temp] = flag;
    }
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    mp.clear();
    if(s1.length() != s2.length()){
        cout<<"Not scrambled\n";
        return 0;
    }
    if(s1.empty() && s2.empty()){
        cout<<"Scrambled\n";
        return 0;
    }
    if(solveMemo(s1,s2)){
        cout<<"Scrambled\n";
    }else{
        cout<<"Not Scrambled\n";
    }
    return 0;
}