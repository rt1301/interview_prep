/****
 * Given an array in which all numbers except two are repeated once.
 * (i.e. we have 2n+2 numbers and n numbers are occurring twice 
 * and remaining two have occurred once)
 * Find those two numbers in the most efficient way.  
 ****/
#include<bits/stdc++.h>
using namespace std;
// O(nlogn) solution
vector<int>uniqueElement(vector<int>v){
    int a = 0;
    vector<int>res;
    sort(v.begin(),v.end());
    for (size_t i = 0; i < v.size()-1; i++)
    {
        if(v[i] != v[i+1]) res.push_back(v[i]);
        else i++;
    }
    return res;
}
int main(){
    vector<int>arr = {2, 3, 7, 9, 11, 2, 3, 11};
    vector<int>ans = uniqueElement(arr);
    for (auto i = ans.begin(); i!=ans.end() ; i++)
    {
        cout<<*i<<" ";
    }
    
    return 0;
}