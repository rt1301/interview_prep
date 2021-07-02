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
    int search(vector<int>v,int curr){
        for(int i=0;i<v.size();i++){
            if(v[i] == curr){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        int i = search(inorder,preorder[0]);
        
        root->left = buildTree(vector<int>(preorder.begin()+1, preorder.begin()+i+1), vector<int>(inorder.begin(), inorder.begin() + i));
        root->right = buildTree(vector<int>(preorder.begin()+1+i, preorder.end()), vector<int>(inorder.begin() + i + 1, inorder.end()));
        return root;
    }
   
};