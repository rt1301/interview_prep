#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int x = 0;
    cin>>x;
    int ans = 0;
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;i++){
        if(x>0){
            ans+=x/a[i];
            x-=x/a[i]*a[i];
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}