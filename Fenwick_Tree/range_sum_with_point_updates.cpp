#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>bits;
void update(int idx, int val){
    while(idx<=n){
        bits[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int query(int i){
    int ans = 0;
    while (i>0)
    {
        ans+=bits[i];
        i-=(i&-(i));
    }
    return ans;
}
int main(){
    cin>>n;
    bits = vector<int>(n+1);
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i]);
    }
    int q;
    cin>>q;
    while (q--)
    {
        int c;
        cin>>c;
        if(c == 1){
            int l,r;
            cin>>l>>r;
            int ans = query(r)-query(l-1);
            cout<<ans<<endl;
        }else{
            int index,val;
            cin>>index>>val;
            update(index,-arr[index]); //previous contribution of index is nullify
            arr[index] = val;
            update(index,val);
        }
    }
    return 0;
}