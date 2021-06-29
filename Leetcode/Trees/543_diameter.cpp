#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int height(TreeNode*root, int &ans){
        if(root == NULL) return 0;
        int left_height = height(root->left,ans);
        int right_height = height(root->right,ans);
        
        ans = max(ans,left_height+right_height+1);
        return 1 + max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = INT_MIN;
        height(root,ans);
        return ans-1;
    }
};
 