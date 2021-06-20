#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow_p = head;
        ListNode*fast_p = head;
        while(slow_p && fast_p && fast_p->next){
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if(slow_p == fast_p){
                return true;
            }
        }
        return false;
    }
};