#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*left;
    Node*right;
    int val;
    Node(int val){
        this->left=this->right=nullptr;
        this->val=val;
    }
};
Node* createBST(int arr[],int n,int start,int end){
    if(start>end){
        return nullptr;
    }
    int mid = start + (end-start)/2;
    Node *root = new Node(arr[mid]);
    root->left = createBST(arr,n,start,mid-1);
    root->right = createBST(arr,n,mid+1,end);
    return root;
}
void preorder(Node*root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int ht(Node*root){
    if(!root) return 0;
    int left = ht(root->left);
    int right = ht(root->right);
    return 1 + max(left,right);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node*root;
    root = createBST(arr,size,0,size-1);
    preorder(root);
    cout<<endl<<ht(root);
    return 0;
}
