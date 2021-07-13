/****
 * Given a string, a partitioning of the string is a palindrome partitioning 
 * if every substring of the partition is a palindrome. For example, 
 * “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
 * Determine the fewest cuts needed for a palindrome partitioning of a given string.
 ****/
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j){
    if(i>=j || isPalindrome(s,i,j)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int mn = INT_MAX;
    for(int k = i; k<j;k++){
        int temp_ans = solve(s,i,k) + solve(s,k+1,j) + 1;
        mn = min(mn, temp_ans);
    }
    return t[i][j] = mn;
}
int main(){
    memset(t,-1,sizeof(t));
    string s;
    cin>>s;
    int ans = solve(s,0,s.length()-1);
    cout<<ans;
    return 0;
}