#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>&v, int d){
    int n = v.size();
    d = d%n;
    int factor = __gcd(d,n);
    for(int i=0;i<factor;i++){
        int temp = v[i];
        int j = i;
        while (true)
        {
            int k = j+d;
            if(k>=n){
                k = k-n;
            }
            if(k == i){
                break;
            }
            v[j] = v[k];
            j = k;
        }
        v[j] = temp;
    }
}
void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v = {1,2,3,4,5,6,7};
    int d = 3;
    cout<<"Before Rotation\n";
    print(v);
    cout<<"After Rotation\n";
    rotate(v,d);
    print(v);
    return 0;
}