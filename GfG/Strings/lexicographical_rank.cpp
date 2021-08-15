/****
 * Given a string, find its rank among all its permutations sorted lexicographically. 
 * For example, rank of “abc” is 1, rank of “acb” is 2, and rank of “cba” is 6. 
 ****/
#include<bits/stdc++.h>
using namespace std;
int MAX_CHAR = 256;
int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int f1 = 1;
    for(int i=2;i<=n;i++){
        f1*=i;
    }
    return f1;
}

void populateCount(vector<int>&count,string s){
    for(int i=0;i<s.length();i++){
        count[s[i]]++;
    }
    for(int i=1;i<MAX_CHAR;i++){
        count[i] += count[i-1];
    }
}

void updateCount(vector<int>&count,char ch){
    for(int i = ch; i<MAX_CHAR;i++){
        count[i]--;
    }
}

int findRank(string s){
    vector<int>count(MAX_CHAR,0);
    int n = s.length();
    int rank = 1;
    int mul = fact(n);

    // Populate the count array such that count[i]
    // contains count of characters which are present
    // in str and are smaller than i
    populateCount(count,s);

    for(int i=0;i<n;i++){
        mul/=(n-i);
        // count number of chars smaller than str[i]
        // fron str[i+1] to str[len-1]
        rank+=(count[s[i]-1]*mul);

        updateCount(count,s[i]);
    }

    return rank;
}

int main(){
    string s;
    cin>>s;
    cout<<findRank(s);
    return 0;
}