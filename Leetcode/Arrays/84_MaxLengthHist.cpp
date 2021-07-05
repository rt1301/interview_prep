#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int max_area = 0;
    int tp;
    int area = 0;
    int i = 0;
    stack<int> s;
    int n = heights.size();
    while (i < n)
    {
        if (s.empty() || heights[s.top()] <= heights[i])
        {
            s.push(i++);
        }
        else
        {
            tp = s.top();
            s.pop();
            area = s.empty() ? heights[tp] * i : heights[tp] * (i - s.top() - 1);
            max_area = max(max_area, area);
        }
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        area = s.empty() ? heights[tp] * i : heights[tp] * (i - s.top() - 1);
        max_area = max(max_area, area);
    }

    return max_area;
}