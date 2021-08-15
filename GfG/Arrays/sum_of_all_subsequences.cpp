/****
 * Given an array of n integers. The task is to find the sum of each sub-sequence of 
 * the array.
 ****/
#include<bits/stdc++.h>
using namespace std;
int sumSub(vector<int>v){
    int sum = 0;
    for(int i=0;i<v.size();i++){
        sum+=(v[i]);
    }
    return sum*pow(2,v.size()-1);
    // Also written as sum*(1<<(v.size()-1))
}
int main(){
    vector<int>v = {6,8,5};
    cout<<sumSub(v);
    return 0;
}