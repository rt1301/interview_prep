#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*left;
    Node*right;
    int data;
    Node(int val){
        this->data = val;
        this->left=this->right=nullptr;
    }
};

int checkBalanced(Node*root,bool &flag){
    if(!root) return 0;

    int left_height = checkBalanced(root->left,flag);
    int right_height = checkBalanced(root->right,flag);

    if(abs(left_height - right_height)<=1){
        flag = true;
    }else{
        flag = false;
    }

    return 1 + max(left_height,right_height);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(8);
    root->right->right = new Node(6);

    bool flag = false;

    int ht = checkBalanced(root,flag);
    cout<<"Height "<<ht;
    if(flag){
        cout<<"\nTrees are balanced";
    }else{
        cout<<"\nTrees are not balanced";
    }
    return 0;
}