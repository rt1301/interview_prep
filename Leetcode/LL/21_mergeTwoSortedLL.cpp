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
    void moveNode(ListNode **destRef, ListNode **srcRef){
        ListNode *newNode = *srcRef;
        if(newNode){
            //Advance the source ptr
            *srcRef = newNode->next;
//             Link the old dest to newnode
            newNode->next = *destRef;
//             move the dest to point towards new node
            *destRef = newNode;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *tail = &dummy;
        dummy.next = nullptr;
        while(1){
            if(l2 == nullptr){
                tail->next = l1;
                break;
            }
            else if(l1 == nullptr){
                tail->next = l2;
                break;
            }
            if(l1->val<=l2->val){
                moveNode(&(tail->next),&l1);
            }else{
                moveNode(&(tail->next),&l2);
            }
            tail = tail->next;
        }
        return dummy.next;
    }
};