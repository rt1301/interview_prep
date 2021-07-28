/****
 * Given an array of distinct elements, find previous greater element 
 * for every element. If previous greater element does not exist, print -1.
 * Problem Statement - https://www.geeksforgeeks.org/previous-greater-element/
 ****/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>v;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(-1);
        }else if(!s.empty() && s.top()>arr[i]){
            v.push_back(s.top());
        }else if(!s.empty() && s.top()<=arr[i]){
            while (!s.empty() && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.empty()) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}