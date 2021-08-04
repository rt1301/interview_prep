/****
 * Given a stack, the task is to sort it such that the top of the stack has the 
 * greatest element.
 ****/
#include<bits/stdc++.h>
using namespace std;
void helper(stack<int> &stack, int val)
{
    if (stack.empty() || val > stack.top())
    {
        stack.push(val);
        return;
    }
    int top = stack.top();
    stack.pop();
    helper(stack, val);
    stack.push(top);
}
void SortedStack ::sort()
{
    //Your code here
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    sort();
    helper(s, top);
}