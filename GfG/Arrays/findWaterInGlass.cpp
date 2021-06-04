/****
 * Program to find amount of water in a given glass
 * There are some glasses with equal capacity as 1 litre.
 * You can put water to the only top glass. If you put more than 1-litre water to 1st glass
 * water overflows and fills equally in both 2nd and 3rd glasses. 
 * Glass 5 will get water from both 2nd glass and 3rd glass and so on. 
 * If you have X litre of water and you put that water in a top glass, 
 * how much water will be contained by the jth glass in an ith row?
 * 
 * Similar to Pascal's triangle
 ****/
#include<bits/stdc++.h>
using namespace std;
float findWater(int i,int j,float X){
    if(j>i){
        cout<<"Incorrect input";
        return -1;
    }

    float glass[i*(i+1)/2];
    memset(glass,0,sizeof(glass));

    // put all water in glass 1
    int index = 0;
    glass[index] = X;
    // now go downwards and distribute water to the remaining glasses
    for(int row = 1;row<=i;row++){

        for(int col = 1;col<=row;col++,index++)
        {
            // take water from parent glass
            X = glass[index];
            // Keep the reqd water in glass and distribute the rest 
            glass[index] = (X>=1.0f)?1.0f:X;
            // Get the remaining water
            X = (X>=1.0f)?X-1:0.0f;
            // Distribute the remaining amount to the down glasses
            glass[index+row]+=X/2;
            glass[index+row+1]+=X/2;
        }
    }
    // The index of jth glass in ith row will
    // be i*(i-1)/2 + j - 1
    return glass[(i*(i-1)/2) + j - 1];
}
int main(){
    int i = 2, j = 2;
    float X = 2.0; // Total amount of water
    cout << "Amount of water in jth glass of ith row is: "<<findWater(i, j, X);
    return 0;
    
}