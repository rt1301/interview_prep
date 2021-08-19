/****
 * Given two strings (of lowercase letters), a pattern and a string. 
 * The task is to sort string according to the order defined by pattern. 
 * It may be assumed that pattern has all characters of the string and 
 * all characters in pattern appear only once.
 ****/
#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>pos;
bool compare(char &a, char &b){
    return pos[a]<pos[b];
}
int main(){
    string str,pat;
    cin>>pat>>str;
    for(int i=0;i<pat.length();i++){
        pos[pat[i]] = i;
    }
    cout<<"Before Sorting"<<endl<<str<<endl;
    cout<<"After Sorting\n";
    sort(str.begin(),str.end(),compare);
    cout<<str;
    return 0;
}
