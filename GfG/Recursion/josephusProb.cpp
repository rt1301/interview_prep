/****
 * Josephus Problem - https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
 ****/
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&v,int k, int index, int &ans){
    if(v.size() == 1) { // base condition
        ans = v[0];
        return;
    } 

    index = (index+k)%(v.size());
    v.erase(v.begin()+index); // induction step

    solve(v,k,index,ans); // hypothesis

}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for (size_t i = 0; i < n; i++)
    {
        v[i] = i+1;
    }

    k = k-1;
    int index = 0;
    int ans = -1;
    solve(v,k,index,ans);
    cout<<"Safe Position in the circle is "<<ans;
    return 0;
}