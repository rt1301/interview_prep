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
bool flag = true;
void checkSum(Node*root){
    if(!root){
        return;
    }
    int x = root->data;
    if(root->left){
        x-=root->left->data;
    }
    if(root->right){
        x-=root->right->data;
    }
    if(x != 0 && !isLeaf(root)){
        flag = false;
        return;
    }
    checkSum(root->left);
    checkSum(root->right);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    checkSum(root);

    if(flag){
        cout<<"Property is valid";
    }else{
        cout<<"Property is not valid";
    }
    return 0;
}