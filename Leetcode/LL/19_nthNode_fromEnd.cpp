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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ref = head;
        int size = 1;
        while(ref->next != nullptr){
            size++;
            ref = ref->next;
        }
        ref = head;
        if(size == n){
            head = head->next;
            return head;
        }
        int newSize = size-n-1;
        while(ref->next != nullptr && newSize--){
            ref = ref->next;
        }
        ListNode *next = ref->next;
        if(next->next){
            ref->next = next->next;
        }else{
            ref->next = nullptr;
        }
        delete next;
        return head;
    }
};