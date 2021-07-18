#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::solve(int A, int B, int C, int D)
{
    if (D == 0)
        return {};
    set<int> s;
    vector<int> ans;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    while (!s.empty())
    {
        auto it = *s.begin();
        s.erase(s.begin());
        if (ans.size() == D)
            break;
        ans.push_back(it);
        int p1 = it * A;
        int p2 = it * B;
        int p3 = it * C;
        s.insert(p1);
        s.insert(p2);
        s.insert(p3);
    }
    return ans;
}
