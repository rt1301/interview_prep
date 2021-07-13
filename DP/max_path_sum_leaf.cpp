/****
 * Given a binary tree in which each node element contains a number. 
 * Find the maximum possible sum from one leaf node to another. 
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left;
    Node*right;
    int data;
    Node(int val){
        left = right = nullptr;
        data = val;
    }
};
int solve(Node*root, int &res){
    // Base Condition
    if(!root) return 0;
    // Hypothesis
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    // Induction
    int temp = max(l,r) + root->data;
    int ans = max(temp,l+r+root->data);
    res = max(res,ans);
    return temp;
}
int main(){
    int res = INT_MIN;
    Node *root = new Node(-15);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(-8);
    root->left->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->right->right->right= new Node(0);
    root->right->right->right->left= new Node(4);
    root->right->right->right->right= new Node(-1);
    root->right->right->right->right->left= new Node(10);
    solve(root,res);
    cout << "Max pathSum of the given binary tree is "
         << res;
    return 0;
}