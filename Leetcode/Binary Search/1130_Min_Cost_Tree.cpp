#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        vector<int> st = {INT_MAX};
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {

            while (st.back() <= arr[i])
            {
                int x = st.back();
                st.pop_back();

                ans += (x * min(st.back(), arr[i]));
            }

            st.push_back(arr[i]);
        }
        for (int i = 2; i < st.size(); i++)
        {
            ans += (st[i] * st[i - 1]);
        }

        return ans;
    }
};