#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
void traverse(TreeNode *root, int d)
{
    if (!root)
        return;
    mp[d].push_back(root->val);
    traverse(root->left, d + 1);
    traverse(root->right, d + 1);
}
vector<vector<int>> Solution::levelOrder(TreeNode *A)
{
    mp.clear();
    vector<vector<int>> ans;
    traverse(A, 0);
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}