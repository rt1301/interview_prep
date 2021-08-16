#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    for (size_t  i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]] > (n/2)){
            cout<<"Majority Element is: "<<arr[i];
            break;
        }
    }
    
    return 0;
}