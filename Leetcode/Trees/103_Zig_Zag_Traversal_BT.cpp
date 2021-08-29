#include<bits/stdc++.h>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        bool flag = true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            while (n > 0)
            {
                TreeNode *x = q.front();
                if (x)
                {
                    temp.push_back(x->val);
                }
                q.pop();
                if (x && x->left)
                {
                    q.push(x->left);
                }
                if (x && x->right)
                {
                    q.push(x->right);
                }
                n--;
            }
            if (!flag)
            {
                reverse(temp.begin(), temp.end());
            }
            if (!temp.empty())
            {
                ans.push_back(temp);
            }
            flag = !flag;
        }
        return ans;
    }
};