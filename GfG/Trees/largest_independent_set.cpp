#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
set<int>ans;
bool isLeaf(Node*root){
    if(root->left == nullptr && root->right == nullptr) return true;
    return false;
}
void dfs(Node*root){
    if(!root) return;
    if(isLeaf(root)){
        ans.insert(root->data);
    }
    dfs(root->left);
    dfs(root->right);
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);
    dfs(root);
    ans.insert(root->data);
    cout<<ans.size();
    return 0;
}