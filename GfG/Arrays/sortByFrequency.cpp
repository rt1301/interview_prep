/****
 * Print the elements of an array in the decreasing frequency if 2 numbers 
 * have same frequency then print the one which came first. 
 ****/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,pair<int,int>>p1,pair<int,pair<int,int>>p2){
    if(p1.second.second != p2.second.second){
        return p1.second.second>p2.second.second;
    }else{
        return p1.second.first<p2.second.first;
    }
}
void sortByFreq(int arr[],int n){
    unordered_map<int,pair<int,int>>mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i]) != mp.end()){
            mp[arr[i]].second++;
        }else{
            mp[arr[i]] = make_pair(i,1);
        }
        
    }
    vector<pair<int,pair<int,int>>>v;
    for(auto it=mp.begin();it!=mp.end();it++){
        v.push_back(make_pair(it->first,it->second));
    }
    sort(v.begin(),v.end(),compare);
    // Printing the Sorted sequence
    for (int i = 0; i < v.size(); i++)
    {
        int count = v[i].second.second;
        while (count--)
            cout << v[i].first << " ";
    }
}


int main(){
    int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortByFreq(arr,n);
    return 0;
}