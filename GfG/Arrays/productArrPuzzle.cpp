/****
 * Given an array arr[] of n integers, construct a Product Array prod[] (of same size)
 * such that prod[i] is equal to the product of all the elements of arr[] except arr[i].
 *  Solve it without division operator in O(n) time.
 * Ex- Input: arr[]  = {10, 3, 5, 6, 2}
 * Output: prod[]  = {180, 600, 360, 300, 900}
 ****/
#include<bits/stdc++.h>
using namespace std;
vector<int>arrayPuzzle(vector<int>v){
    vector<int>prod(v.size(),1);
    int temp = 1;
    for (size_t i = 0; i < v.size(); i++)
    {
        prod[i]*=temp;
        temp*=v[i];
    }
    temp  = 1;
    for(int i = v.size()-1;i>=0;i--){
        prod[i]*=temp;
        temp*=v[i];
    }
    return prod;
}

int main(){
    vector<int>v = {10, 3, 5, 6, 2};
    vector<int>prod = arrayPuzzle(v);
    for (auto i = prod.begin(); i != prod.end(); i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}