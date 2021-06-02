/****
 * Given an array of integers, find anyone combination 
 * of four elements in the array whose sum is equal to a given value X.
 ****/
#include<bits/stdc++.h>
using namespace std;
// Hash Map solution - O(n^2) complexity
void fourEleSum(int arr[],int n,int x){
    unordered_map<int,pair<int,int>>mp;
    // Store all possible pairs in Hash Map
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            mp[arr[i] + arr[j]] = {i,j};
        }
        
    }
    // Traverse through all pairs and search
    // for X - (current pair sum).
    for (int i = 1; i < n-1; i++)
    {
        for(int j = i+1; j<n; j++){
            int sum = arr[i] + arr[j];
            if(mp.find(x-sum) != mp.end()){
                // Making sure that all elements are
                // distinct array elements and an element
                // is not considered more than once.
                pair<int,int>p = mp[x-sum];
                if(p.first != i && p.first !=j && p.second !=j && p.second !=i){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[p.first]<<" "<<arr[p.second];
                    return;
                }
            }
        }
    }
    
    
}

int main(){
    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
    fourEleSum(arr,n,X);
    return 0;
}