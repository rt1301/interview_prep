/****
 * Given two sorted arrays, find their union and intersection.
 ****/
#include<bits/stdc++.h>
using namespace std;
vector<int>unionOfTwoArr(vector<int>v1,vector<int>v2){
    vector<int>v;
    set<int>s;
    for (size_t i = 0; i < v1.size(); i++)
    {
        s.insert(v1[i]);
    }
    for (size_t i = 0; i < v2.size(); i++)
    {
        s.insert(v2[i]);
    }
    for(auto it = s.begin();it!=s.end();it++) v.push_back(*it);
    return v;
}
vector<int>intersection(vector<int>v1,vector<int>v2){
    vector<int>v;
    set<int>s;
    set<int>d;
    for (size_t i = 0; i < v1.size(); i++)
    {
        s.insert(v1[i]);
    }
    for (size_t i = 0; i < v2.size(); i++)
    {
        if(s.find(v2[i]) != s.end()){
            v.push_back(v2[i]);
        }
    }
    return v;
    
}
void printVector(vector<int>v){
    for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";
    cout<<endl;
}
int main(){
    vector<int>arr1 = {1, 2, 2, 2, 3};
    vector<int>arr2 = {2, 3, 4, 5};
    vector<int>u = unionOfTwoArr(arr1,arr2);
    vector<int>i = intersection(arr1,arr2);
    printVector(u);
    printVector(i);
    return 0;
}