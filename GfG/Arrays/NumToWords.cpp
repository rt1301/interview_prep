/****
 * Write a function to convert a given number into words.
 * Input:
    N = 438237764
    Output: forty three crore eighty two lakh thirty seven thousand seven hundred and 
    sixty four
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> digit = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ",
                            "thirteen ", "fourteen ", "fifteen ",
                            "sixteen ", "seventeen ", "eighteen ",
                            "nineteen "};
    vector<string> tens = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ",
                           "ninety "};
    string numToWords(int n, string str)
    {
        string s = "";
        if (n > 19)
        {
            s += (tens[n / 10] + digit[n % 10]);
        }
        else
        {
            s = digit[n];
        }

        if (n)
        {
            s += str;
        }
        return s;
    }
    string convertToWords(long n)
    {
        // code here
        string ans;

        ans += numToWords((n / 10000000), "crore ");

        ans += numToWords((n / 100000) % 100, "lakh ");

        ans += numToWords((n / 1000) % 100, "thousand ");

        ans += numToWords((n / 100) % 10, "hundred ");

        if (n > 100 && n % 100)
        {
            ans += "and ";
        }

        ans += numToWords((n % 100), "");
        return ans;
    }
};