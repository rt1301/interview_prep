/****
 * Replace all the spaces in a string with '%20'.
 * Assumption : We have enough space to accomodate addition chars
 * Preferebly in place
 ****/
#include<bits/stdc++.h>
using namespace std;

void urlify(string &s,int len){
    int numOfSpaces = 0; // to count the number of spaces
    for(int i=0;i<len;i++){
        if(s[i] == ' '){
            numOfSpaces++;
        }
    }
    int extendedLength = len + 2*numOfSpaces; // new length of the string
    int i = extendedLength-1; // pointer to end of the string
    for(int j=len-1;j>=0;j--){
        if(s[j] != ' '){
            s[i--] = s[j]; // copy the character to the end of the string
        }
        else{
            s[i--] = '0';
            s[i--] = '2';
            s[i--] = '%';
        }
    }
}

int main(){
    string str = "Mr John Smith    ";
    cout << "Actual string   : " << str << endl;
    urlify(str, 13); //Length of "Mr John Smith" = 13
    cout << "URLified string : " << str << endl;
    return 0;
}