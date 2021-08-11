/****
 * You have an array containing n elements initially all 0. You need to 
 * do a number of update operations on it. In each update you specify l, r and val 
 * which are the starting index, ending index and value to be added. After each update, 
 * you add the 'val' to all elements from index l to r. After 'u' updates are over, 
 * there will be q queries each containing an index for which you have to 
 * print the element at that index.
 ****/
#include<bits/stdc++.h>
using namespace std;
int query(int bit[],int n, int w){
    int ans = 0;
    while (w>0)
    {
        ans+=bit[w];
        w-=(w&(-w));
    }
    return ans;
}
void update(int bit[],int n, int i, int incr){
    while (i<=n)
    {
        bit[i]+=incr;
        i+=(i&(-i));
    }
}
void solve(){
    int n;
    cin>>n;
    int bit[n+10]={0};
    int u;
    cin>>u;
    while (u--)
    {
        int l,r,incr;
        cin>>l>>r>>incr;
        l++;r++;
        update(bit,n,l,incr);
        update(bit,n,r+1,-incr);
    }
    int q;
    cin>>q;
    while (q--)
    {
        int w;
        cin>>w;
        w++;
        cout<<query(bit,n,w)<<endl;
    }
    
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}