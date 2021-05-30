#include<bits/stdc++.h>
using namespace std;
int searchString(vector<string>s,string key){
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == key) return i;
    }
    // Worst case of this search is O(n). We cannot implement something better than O(n)
    // coz you could have an array with all empty strings and one non empty string
    // in that case you have to look for all the elements in the array
    return -1;
}

int main(){
    vector<string> s = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    int index = searchString(s,"ball");
    cout<<index;
    return 0;
}