/****
 * Implement a method to perform basic string compression using the counts
 * of repeated Characters. 
 * eg: aabcccccaaa => a2b1c5a3
 ****/
#include<bits/stdc++.h>
using namespace std;
string compress(string s){
    vector<tuple<int,int,char>>cont;
    string temp = "";
    bool flag = false;
    int stIndex=0,enIndex=0;
    for(int i=0;i<s.length()-1;i++){
        if (s[i] == s[i + 1])
        {
            if(!flag){
                stIndex = i;
            }
            flag = true;
        }else{
            flag = false;
            enIndex = i;
            cont.push_back(make_tuple(stIndex,enIndex,s[i]));
            stIndex = i+1;
        }
    }
    enIndex = s.length()-1;
    cont.push_back(make_tuple(stIndex,enIndex,s[enIndex]));
    string res;
    for(int i=0;i<(int)cont.size();i++){
        int size = get<1>(cont[i]) - get<0>(cont[i]) + 1;
        res.push_back(get<2>(cont[i]));
        res+=to_string(size);
    }
    if(res.length()>s.length()){
        return s;
    }else{
        return res;
    }
}
int main(){
    std::string str, out;
    std::cout << "Enter a string:\n";
    std::cin >> str;
    out = compress(str);
    std::cout << str << " can be compressed to " << out << std::endl;
    return 0;
}