#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int val){
        left = right = nullptr;
        data = val;
    }
};
bool isLeaf(Node *root){
    if(root && (root->left == nullptr && root->right == nullptr)){
        return true;
    }
    return false;
}
void increment(Node *root, int diff)
{
    if (root->left)
    {
        root->left->data = root->left->data + diff;
        increment(root->left, diff);
    }
    else if (root->right)
    {
        root->right->data = root->right->data + diff;
        increment(root->right, diff);
    }
}
void convertToChildSumTree(Node *root){
    if(!root){
        return;
    }
    convertToChildSumTree(root->left);
    convertToChildSumTree(root->right);
    if(!isLeaf(root)){
        int l = root->left ? root->left->data : 0;
        int r = root->right ? root->right->data : 0;
        int diff = (l+r)-root->data;
        if(diff > 0){
            root->data+=diff;
        }
        else if(diff<0){
            increment(root,-diff);
        }
    }
}
void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node*root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);
    inorder(root);
    convertToChildSumTree(root);
    cout<<endl;
    inorder(root);
    return 0;
}