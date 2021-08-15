#include<bits/stdc++.h>
using namespace std;

void cycleLeader(string &s, int shift, int len){
    char item;
    int j;
    for(int i=1;i<len;i*=3){
        j = i;
        item = s[j+shift];
        do
        {
           if(j&1){
               j = len/2 + j/2;
           }else{
               j = j/2;
           }
           swap(s[j+shift],item);
        } while (j!=i);
    }
}

void moveNumToSecondHalf(string &s){
    int k,lenFirst;
    int lenRem = s.length();
    int shift = 0;
    while (lenRem)
    {
        /* code */
        k = 0;
        while(pow(3,k)+1 <=lenRem){
            k++;
        }
        lenFirst = pow(3,k-1)+1;
        lenRem-=lenFirst;

        cycleLeader(s,shift,lenFirst);

        reverse(s.begin()+shift/2,s.begin()+shift-1);

        reverse(s.begin()+shift, s.begin()+shift+lenFirst/2-1);

        reverse(s.begin() + shift/2, s.begin() + shift+lenFirst/2 - 1);
        shift+=lenFirst;
    }
}

int main(){
    string s = "a1b2c3d4e5f6g7";
    moveNumToSecondHalf(s);
    cout<<s<<endl;
    return 0;
}