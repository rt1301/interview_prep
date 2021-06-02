/****
 * Given a word, find the lexicographically greater permutation of it.
 * For example, lexicographically next permutation of “gfg” 
 * is “ggf” and next permutation of “acb” is “bac”.
 * Note: In some cases, the next lexicographically 
 * greater word might not exist, e.g, “aaa” and “edcba”
 ****/
#include<bits/stdc++.h>
using namespace std;
bool checkIfSorted(string s){
    for(int i=0;i<s.length()-1;i++){
        if(s[i]<s[i+1]) return false;
    }
    return true;
}
string findNextPermutation(string s){
    if(checkIfSorted(s)){
        return s;
    }else{
        char first;
        int index = 0;
        for(int i=s.length()-1;i>0;i--){
            if(s[i]>s[i-1]){
                first = s[i-1];
                index = i-1;
                break;
            }
        }
        for(int i=s.length()-1;i>index;i--){
            if(s[i]>first){
                swap(s[i],s[index]);
                break;
            }
        }
        sort(s.begin()+index+1,s.end());
        return s;
    }
}
int main(){
    string s = "abedc";
    string ans = findNextPermutation(s);
    cout<<ans;
    return 0;
}