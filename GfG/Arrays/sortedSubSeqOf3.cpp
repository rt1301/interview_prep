/****
 * Given an array of n integers, find the 3 elements such that
 * a[i] < a[j] < a[k] and i < j < k in 0(n) time. If
 * there are multiple such triplets, then print any one of them.
 ****/
#include<bits/stdc++.h>
using namespace std;
vector<int>find3Elements(vector<int>a){
    vector<int>v;
    // v.push_back(a[0]);
    for (size_t i = 0; i < a.size()-1; i++)
    {
        if(v.size()>3) break;
        if(a[i]<a[i+1]){
            if(!v.empty() && v[v.size()-1]<a[i]){
                v.push_back(a[i]);
            }
            if(!v.empty() && v[v.size()-1]<a[i+1]){
                v.push_back(a[i+1]);
            }
            if(v.empty()){
                v.push_back(a[i]);
                v.push_back(a[i+1]);
            }
        }
    }
    if(v.size()>3){
        while (v.size()!= 3)
        {
            v.pop_back();
        }
        
    }
    return v;
    
}
int main(){
    vector<int> v = {12, 11, 10, 5, 6, 2, 30};
    vector<int>ans = find3Elements(v);
    cout<<"ANSWER IS\n";
    if(ans.size() == 0){
        cout<<"NO Such Triplet Found";
    }else{
            for (auto i = ans.begin(); i != ans.end(); i++)
        {
            cout<<*i<<" ";
        }
    }
    
    return 0;
}