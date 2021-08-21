#include<bits/stdc++.h>
using namespace std;
int isValid(string ip)
{
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);

    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++)
    {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) == 0)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
            return 0;
    }
    return 1;
}
vector<string> Solution::restoreIpAddresses(string A)
{
    vector<string> ans;
    int l = A.length();
    if (l > 12 || l < 4)
    {
        ans;
    }
    string check = A;
    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);
                if (isValid(check))
                {
                    ans.push_back(check);
                }
                check = A;
            }
        }
    }

    return ans;
}
