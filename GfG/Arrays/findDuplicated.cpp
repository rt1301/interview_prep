/****
 * Given an array of n elements that contains elements from 0 to n-1
 * with any of these numbers appearing any number of times.
 * Find these repeating numbers in O(n) and using only constant memory space.
 ****/
#include<bits/stdc++.h>
using namespace std;
void findDuplicates(vector<int>v){
    int n = v.size();
    // count the frequency
    for(int i=0;i<n;i++){
        v[v[i]%n]+=n;
    }
    for(int i=0;i<n;i++){
        if(v[i] >= 2*n){
            cout<<i<<" ";
        }
    }
}
int main(){
    vector<int> v = {0, 4, 3, 2, 7, 8, 2, 3, 1};
    findDuplicates(v);
    return 0;
}