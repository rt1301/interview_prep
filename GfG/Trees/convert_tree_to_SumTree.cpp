/****
 * Given a Binary Tree where each node has positive and negative values. 
 * Convert this to a tree where each node contains the sum of the left and 
 * right sub trees in the original tree. The values of leaf nodes are changed to 0.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int temp = root->data;
        if (root->left == nullptr && root->right == nullptr)
        {
            root->data = 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);
        root->data = l + r;
        return l + r + temp;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};