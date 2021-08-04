#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool flag = false;
    unordered_set<int> nodes;
    void dfs(TreeNode *root, int k)
    {
        if (!root)
            return;
        if (nodes.size() > 0 && (nodes.find(k - (root->val)) != nodes.end()))
        {
            flag = true;
            return;
        }
        nodes.insert(root->val);
        dfs(root->left, k);
        dfs(root->right, k);
        return;
    }
    bool findTarget(TreeNode *root, int k)
    {
        dfs(root, k);
        return flag;
    }
};