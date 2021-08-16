#include<bits/stdc++.h>
using namespace std;
pair<int,int>maxMin(int arr[],int l, int h){
    pair<int,int>ans;
    if(l == h){
        ans.first = arr[l];
        ans.second = arr[h];
        return ans;
    }else if(h == l+1){
        if(arr[l]>arr[h]){
            ans.first = arr[l];
            ans.second = arr[h];
        }
        else{
            ans.first = arr[h];
            ans.second = arr[l];
        }
        return ans;
    }else{
        int mid = l + (h-l)/2;
        pair<int,int>mml = maxMin(arr,l,mid);
        pair<int,int>mmr = maxMin(arr,mid+1,h);
        if(mml.second < mmr.second){
            ans.second = mml.second;
        }else{
            ans.second = mmr.second;
        }

        if(mml.first>mmr.first){
            ans.first = mml.first;
        }else{
            ans.first = mmr.first;
        }
        return ans;
    }
    return ans;
}
int main(){
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = 6;
    pair<int,int>ans = maxMin(arr,0,n-1);
    cout<<"Min ele is "<<ans.second<<endl;
    cout<<"Max ele is "<<ans.first<<endl;
    return 0;
}