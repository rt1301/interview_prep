// For a given set of number find all its subsets
#include<bits/stdc++.h>
using namespace std;
void printSubsets(vector<int>v){
    unsigned int set_size = pow(2,v.size()); // 2^n set size
    int counter=0,j=0;
    for(counter = 0; counter < set_size; counter++)
    {
      for(j = 0; j < v.size(); j++)
       {
          /* Check if jth bit in the counter is set
             If set then print jth element from set */
          if(counter & (1<<j))             //shift 1 to the jth position,
                                           //counter & (1<<j) extracts the jth element of this binary number
            cout<<v[j]<<" ";
       }
       cout<<endl;
    }
}


int main(){
    vector<int>set = {1,2,3};
    printSubsets(set);
    return 0;
}