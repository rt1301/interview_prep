/****
 * You are given an array of n+2 elements. 
 * All elements of the array are in range 1 to n.
 * And all elements occur once except two numbers which occur twice. 
 * Find the two repeating numbers. 
 ****/
#include<bits/stdc++.h>
using namespace std;

void repeatingNums(int arr[], int n){
    unordered_map<int,int>mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second == 2){
            cout<<"Repeated Element: "<<it->first<<endl;
        }
    }
}
int main(){
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    repeatingNums(arr,arr_size);
    return 0;
}