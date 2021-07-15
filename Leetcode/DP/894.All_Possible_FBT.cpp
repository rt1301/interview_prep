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
    unordered_map<int, vector<TreeNode *>> mp;
    vector<TreeNode *> solve(int n)
    {
        if (mp.find(n) != mp.end())
        {
            return mp[n];
        }
        else
        {
            vector<TreeNode *> ans;
            if (n == 1)
            {
                ans.push_back(new TreeNode(0)); // root
            }
            else if (n % 2 == 1)
            {
                for (int x = 0; x < n; x++)
                {
                    int y = n - 1 - x;
                    for (auto left : solve(x))
                    { // left subtree
                        for (auto right : solve(y))
                        {                                    // right substree
                            TreeNode *bns = new TreeNode(0); //binary tree
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                    }
                }
            }
            mp[n] = ans;
        }

        return mp[n];
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        mp.clear();
        return solve(n);
    }
};