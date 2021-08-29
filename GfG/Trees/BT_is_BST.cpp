/****
 * A program to check if a binary tree is BST or not
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
bool flag = true;
void checkBST(Node *root, int &last){
  if(!root){
    return;
  } 
  checkBST(root->left, last);
  if(last == -1){
      last = root->data;
  }else if(last > root->data){
      flag = false;
      return;
  }else{
      last = root->data;
  }
  checkBST(root->right,last);
}

int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    int last = -1;
    checkBST(root,last);
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}