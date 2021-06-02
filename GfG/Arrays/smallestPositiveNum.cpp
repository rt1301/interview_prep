/****
 * You are given an unsorted array with both positive and negative elements.
 * You have to find the smallest positive number missing from
 * the array in O(n) time using constant extra space. 
 * You can modify the original array.
 ****/
#include<bits/stdc++.h>
using namespace std;
// O(nlogn) solution
int smallestNum(vector<int>v){
    int j = 1;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i]>0 && v[i]==j){
            j++;
            continue;
        }
        if(v[i]>0 && v[i]>j){
            return j;
        }
    }
    return j;
}
// Optimised solution - O(n)
int smallestNumOptimised(vector<int>v){
    vector<bool>present(v.size()+1,false);
    int n = v.size();
    for(int i=0;i<(int)v.size();i++){
        if(v[i]>0 && v[i]<=n){
            present[v[i]] = true;
        }
    }
    for(int i = 1;i<(int)present.size();i++){
        if(!present[i]){
            return i;
        }
    }
    return n+1;
}
int main(){
    vector<int> v = {1, 1, 0, -1, -2};
    int ans = smallestNumOptimised(v);
    cout<<ans;
    return 0;
}