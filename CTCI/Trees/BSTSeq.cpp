#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *right;
    Node *left;
    int data;
    Node(int val)
    {
        this->data = val;
        this->left = this->right = nullptr;
    }
};
void insert(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (!root)
    {
        root = newNode;
        return;
    }
    else
    {
        Node *curr = root;
        while (true)
        {
            if (val <= curr->data)
            {
                if (!curr->left)
                {
                    curr->left = newNode;
                    return;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (!curr->right)
                {
                    curr->right = newNode;
                    return;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }
}
vector<vector<int>> findAllSeq(Node *root)
{
    if (root == NULL)
    {
        vector<int> s;
        vector<vector<int>> seq;
        seq.push_back(s);
        return seq;
    }

    if (root -> left == NULL && root -> right == NULL) {
        vector<int> seq;
        seq.push_back(root -> data);
        vector<vector<int> > v;
        v.push_back(seq);
        return v;
    }

    vector<vector<int>> left, right, res;
    left = findAllSeq(root->left);
    right = findAllSeq(root->right);
    int size = left[0].size() + right[0].size() + 1;

    vector<bool> flag(left[0].size(), 0);
    for (int i = 0; i < right[0].size(); i++)
    {
        flag.push_back(1);
    }

    for (int i = 0; i < left.size(); i++)
    {
        for (int j = 0; j < right.size(); j++)
        {
            do
            {
                vector<int> temp(size);
                temp[0] = root->data;
                int l = 0, r = 0;
                for (int k = 0; k < flag.size(); k++)
                {
                    temp[k + 1] = (flag[k]) ? right[j][r++] : left[i][l++];
                }
                res.push_back(temp);
            } while (next_permutation(flag.begin(), flag.end()));
        }
    }

    return res;
}

void printAllSeq(vector<vector<int>> &AllSeq)
{
    int i = 1;
    for (vector<vector<int>>::iterator iter = AllSeq.begin(); iter != AllSeq.end(); ++iter)
    {
        vector<int> seq = *iter;
        cout << "The " << i << "th sequence is: ";
        i++;
        for (vector<int>::iterator it = seq.begin(); it != seq.end(); ++it)
        {
            cout << ' ' << *it;
        }
        cout << '\n';
    }
}

void bfs(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(8);
    insert(root, 4);
    insert(root, 10);
    insert(root, 20);
    insert(root, 2);
    insert(root, 6);
    vector<vector<int>>V = findAllSeq(root);
    printAllSeq(V);
    return 0;
}