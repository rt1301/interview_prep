#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (!root)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        int temp = max(max(l, r) + root->val, root->val);
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);
        return temp;
    }
    int findMax(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        int l = max(0, findMax(root->left, ans));
        int r = max(0, findMax(root->right, ans));
        ans = max(ans, l + r + root->val);
        return (max(l, r) + root->val);
    }
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        findMax(root, res);
        return res;
    }
};