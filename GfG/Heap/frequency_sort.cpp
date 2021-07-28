/****
 * Print the elements of an array in the decreasing frequency 
 * if 2 numbers have same frequency then print the one which came first. 
 * PS- https://www.geeksforgeeks.org/sort-elements-by-frequency/
 ****/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;
void fillVect(int f, int val)
{
    for (int i = 0; i < f; i++)
    {
        cout << val << " ";
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    priority_queue<pp> mh;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        mh.push({it->second, it->first});
    }
    while (!mh.empty())
    {
        fillVect(mh.top().first, mh.top().second);
        mh.pop();
    }
    cout << endl;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}