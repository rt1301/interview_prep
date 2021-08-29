#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class Node
    {
    public:
        Node *next;
        Node *prev;
        int val;
        int key;
        Node(int k, int v)
        {
            val = v;
            key = k;
            next = prev = NULL;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> mp;
    int cap;
    LRUCache(int capacity)
    {
        //         store keys of cache
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *curr)
    {
        Node *next = head->next;
        curr->next = next;
        curr->prev = head;
        head->next = curr;
        next->prev = curr;
    }
    void deleteNode(Node *curr)
    {
        Node *next = curr->next;
        Node *prev = curr->prev;
        prev->next = next;
        next->prev = prev;
        // delete curr;
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            mp.erase(key);
            deleteNode(resNode);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */