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

void printLeftView(Node *root){
    if(!root){
        cout<<"Tree is empty\n";
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            Node *x = q.front();
            q.pop();
            if (i == 1)
            {
                cout << x->data << " ";
            }
            if (x && x->left)
            {
                q.push(x->left);
            }
            if (x && x->right)
            {
                q.push(x->right);
            }
        }
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);
    printLeftView(root);
    return 0;
}