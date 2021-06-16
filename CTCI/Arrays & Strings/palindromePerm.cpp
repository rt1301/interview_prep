/****
 * Given a string. Write a function to check
 * if it is a permutation of a palindrome
 ****/
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    int len = s.length();
    unordered_map<char, int> mp;
    int spaces = 0;
    for (int i = 0; i < len; i++)
    {
        if (mp[(char)tolower(s[i])])
            mp[(char)tolower(s[i])]++;
        else
            mp[(char)tolower(s[i])] = 1;
        if (s[i] == ' ')
            spaces++;
    }
    int pairs = 0;
    int oddChars = 0;
    if(len%2 == 0){
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first != ' '){
                if (it->second % 2 == 0)
                {
                    pairs += (it->second / 2);
                }
                else
                {
                    pairs += (it->second / 2);
                    oddChars += (it->second - (it->second / 2) * 2);
                }
            }
        }
        pairs+=min(spaces,oddChars);
        
        pairs = pairs-len/2;
        if(pairs == 0) return true;
        return false;
    }else{
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first != ' ')
            {
                if (it->second % 2 == 0)
                {
                    pairs += (it->second / 2);
                }
                else
                {
                    pairs += (it->second / 2);
                    oddChars += (it->second - (it->second / 2) * 2);
                }
            }
        }
        if(pairs == len/2 && (oddChars+spaces == 1)){
            return true;
        }else{
            return false;
        }
    }
}
int main(){
    std::string str("Tact Coa");
    std::cout << "Does \"" << str << "\"  has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    cout<<checkPalindrome(str)<<endl;
    std::string str1("A big Cat");
    std::cout << "Does \"" << str1 << "\" has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    cout << checkPalindrome(str1) << endl;

    std::string str2("Aba cbc");
    std::cout << "Does \"" << str2 << "\" has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    cout << checkPalindrome(str2) << endl;
    return 0;
}