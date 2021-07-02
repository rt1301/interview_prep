#include<bits/stdc++.h>
#define COUNT 3
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

void bfs(Node *root){
    vector<Node*>q;
    vector<int>v;
    vector<vector<Node*>>res;
    q.push_back(root);
    while(!q.empty()){
        res.push_back(q);
        vector<Node*>parents = q;
        q.clear();
        for(Node*parent:parents){
            if(parent->left){
                q.push_back(parent->left);
            }
            if(parent->right){
                q.push_back(parent->right);
            }
        }
    }
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]->val<<" ";
        }
        cout<<endl;
    }
    
}
void postorder(Node* p, int indent=0)
{
    if(p != NULL) {
        if(p->left) postorder(p->left, indent+4);
        if(p->right) postorder(p->right, indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        cout<< p->val << "\n ";
    }
}
void print2DUtil(Node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->val<<"\n"; 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(Node *root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
} 
int main(){
    Node *root = new Node(6); 
    root->left = new Node(3); 
    root->right = new Node(5); 
    root->left->left = new Node(2); 
    root->left->right = new Node(5); 
    root->right->right = new Node(4); 
    root->left->right->left = new Node(7); 
    root->left->right->right = new Node(4);
    // print2D(root);
    // cout<<endl;
    bfs(root);  
    // cout<<endl;
    // preorder(root);
    return 0; 
}