/****
 * Check if a Binary Tree is Height Balanced
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int x){
        left = right = nullptr;
        data = x;
    }
};
int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}
int checkBalancedBT(Node *root){
    if(!root){
        return 1;
    }
    int l = height(root->left);
    int r = height(root->right);

    if(abs(l-r)<=1 && checkBalancedBT(root->left) && checkBalancedBT(root->right)){
        return 1;
    }
    return 0;
}
// Approach 2
bool isBalanced(Node *root, int *height){
    if(!root){
        *height = 0;
        return 1;
    }
    int lh=0,rh=0;
    int l=0,r=0;

    l = isBalanced(root->left,&lh);
    r = isBalanced(root->right,&rh);

    *height = 1 + max(lh,rh);

    if(abs(lh-rh)<=2){
        return 0;
    }else{
        return l && r;
    }
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    if(checkBalancedBT(root)){
        cout<<"Tree is balanced";
    }else{
        cout<<"Tree is not balanced";
    }
    cout<<endl;
    int height = 0;
    if (isBalanced(root,&height) == 1)
    {
        cout << "Tree is balanced";
    }
    else
    {
        cout << "Tree is not balanced";
    }
    return 0;
}