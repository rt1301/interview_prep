#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adjm(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout<<"Adjacency Matrix is: \n";
    for (size_t i = 1; i < adjm.size(); i++)
    {
        for (size_t j = 1; j < adjm[i].size(); j++)
        {
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}