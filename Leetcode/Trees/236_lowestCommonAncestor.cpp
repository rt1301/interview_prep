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
    bool findPath(vector<TreeNode*>&a,TreeNode*root,int key){
        if(root == nullptr){
            return false;
        }
        a.push_back(root);
        if(root->val == key){
            return true;
        }
        if((root->left && findPath(a,root->left,key)) || (root->right && findPath(a,root->right,key))){
            return true;
        }
        a.pop_back();
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a;
        vector<TreeNode*>b;
        if(!findPath(a,root,p->val) || !findPath(b,root,q->val)){
            return NULL;
        }
        int i;
        for(i=0;i<a.size()&&i<b.size();i++){
            if(a[i] != b[i])
            {
                break;
            }
        }
        return a[i-1];
    }
};