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
void levelOrder(Node*root){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while(n>0){
            auto x = q.front();
            cout<<x->data<<" ";
            q.pop();
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
            n--;
        }
        cout<<endl;
    }
    
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    levelOrder(root);
    return 0;
}