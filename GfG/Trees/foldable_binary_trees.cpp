#include<bits/stdc++.h>
using namespace std;
bool helper(Node *n1, Node *n2)
{
    if (!n1 && !n2)
    {
        return true;
    }
    if (!n1 || !n2)
    {
        return false;
    }
    return helper(n1->left, n2->right) && helper(n1->right, n2->left);
}
bool IsFoldable(Node *root)
{
    // Your code goes here
    if (!root)
    {
        return true;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    return helper(root->left, root->right);
}