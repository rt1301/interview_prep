#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        else{
            struct ListNode*temp = node->next;
 
            node->val = node->next->val;

            node->next = node->next->next;

            delete temp;
        }
    }
};