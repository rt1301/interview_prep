#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(struct Node *root, int k)
{
    if (!root || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        ans.push_back(root->data);
    }
    dfs(root->left, k - 1);
    dfs(root->right, k - 1);
}
vector<int> Kdistance(struct Node *root, int k)
{
    // Your code here
    ans.clear();
    if (k == 0)
    {
        return {root->data};
    }
    dfs(root, k);
    return ans;
}