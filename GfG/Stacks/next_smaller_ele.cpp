/****
 * Given an array of integers, find the nearest smaller number 
 * for every element such that the smaller element is on left side.
 * Problem Statement - https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
 ****/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    stack<int>s;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        if(s.empty()) v[i] = -1;
        else if(!s.empty() && s.top()<a[i]){
            v[i] = s.top();
        }else if(!s.empty() && s.top()>=a[i]){
            while(!s.empty() && s.top()>=a[i]) s.pop();
            if(s.empty()) v[i] = -1;
            else v[i] = s.top();
        }
        s.push(a[i]);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
