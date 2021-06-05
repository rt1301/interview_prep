/****
 * Given a number , find the next higher number which has the exact 
 * same set of digits as the original number. 
 * For example: given 38276 return 38627
 ****/
#include<bits/stdc++.h>
using namespace std;

int nextHigherNum(int n){
    vector<int>v;
    while(n!=0){
        int temp = n%10;
        v.push_back(temp);
        n/=10;
    }
    reverse(v.begin(),v.end());
    next_permutation(v.begin(),v.end());
    int finalAns = 0;
    int pw = 0;
    for(auto it = v.rbegin();it!=v.rend();it++){
        finalAns += (int)(*it * ceil(pow(10, pw)));
        pw++;
    }
    return finalAns;
}

int main(){
    int s = 38276;
    int ans = nextHigherNum(s);
    cout<<endl<<ans;
    return 0;
}