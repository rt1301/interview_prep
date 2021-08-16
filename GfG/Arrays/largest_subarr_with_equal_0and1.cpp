/****
 * Given an array containing only 0s and 1s, find the largest 
 * subarray which contains equal no of 0s and 1s. The expected time complexity is O(n). 
 ****/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    int c_sum = 0;
    int stIndex = -1,enIndex = -1;
    int len = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            c_sum++;
        }else{
            c_sum--;
        }
        if(c_sum == 0){
            if(len<(i+1)){
                stIndex = 0;
                enIndex = i;
                len = i+1;
            }
        }
        if(mp.find(c_sum) != mp.end()){
            int prevIndex = mp[c_sum]+1;
            int newLen = i-prevIndex + 1;
            if(len<newLen){
                stIndex = prevIndex;
                enIndex = i;
                len = newLen;
            }
        }
        if(mp.find(c_sum) == mp.end()){
            mp[c_sum] = i;
        }
    }

    cout<<"Max Subarray with equal 0s and 1s is between "<<stIndex<<" "<<enIndex;
    return 0;
}
