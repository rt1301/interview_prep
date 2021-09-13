#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        if (!root)
        {
            return "";
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
            {
                s.push_back('#');
                s.push_back(',');
            }
            else
            {
                s.append(to_string(node->val) + ',');
            }
            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                curr->left = nullptr;
            }
            else
            {
                TreeNode *newNode = new TreeNode(stoi(str));
                curr->left = newNode;
                q.push(newNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                curr->right = nullptr;
            }
            else
            {
                TreeNode *newRightNode = new TreeNode(stoi(str));
                curr->right = newRightNode;
                q.push(newRightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));