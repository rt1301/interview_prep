#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*left;
    Node*right;
    int val;
    Node(int val){
        this->val = val;
        this->right = this->left = nullptr;
    }
};

void succesor(Node*root, int val, int &parent){
    if(!root) return;
    if(root->left && root->left->val == val){
        parent = root->val;
        return;
    }
    if(root->right && root->right->val == val){
        parent = root->val;
        return;
    }
    succesor(root->left,val,parent);
    succesor(root->right,val,parent);
}

int main(){
    Node *root = new Node(8); 
    root->left = new Node(4); 
    root->right = new Node(10); 
    root->left->left = new Node(2); 
    root->left->right = new Node(6); 
    root->left->right->left = new Node(5); 
    root->left->right->right = new Node(7); 
    root->right->right = new Node(20); 
    int val = 6;
    int parent = 0;
    succesor(root,val,parent);
    if(parent == 0){
        cout<<"Parent Node doesn't exists";
    }else{
        cout<<"PARENT\t"<<parent;
    }
    return 0;
}