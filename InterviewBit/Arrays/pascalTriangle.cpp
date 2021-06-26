#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >solve(int A) {

    vector<vector<int>>pas;
    for(int i=0;i<A;i++){
        vector<int>row(i+1,1);
        for(int j=0;j<=i;j++){
            if(j==i || j==0){
               row[j] = 1; 
            }else{
                row[j] = pas[i-1][j-1] + pas[i-1][j];
            }
        }
        pas.push_back(row);
    }
    return pas;
}