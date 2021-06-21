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
    int getSize(ListNode *h){
        int size = 0;
        ListNode*ref=h;
        while(ref != nullptr){
            size++;
            ref = ref->next;
        }
        return size;
    }
    ListNode *interesectHelper(ListNode *a, ListNode*b, int d){
        ListNode*c1 = a;
        ListNode*c2 = b;
        while(d--){
            if(c1 == nullptr){
                return nullptr;
            }
            c1 = c1->next;
        }
        while(c1 && c2){
            if(c1 == c2){
                return c1;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        return nullptr;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0,c2=0;
        ListNode*refA = headA;
        ListNode*refB = headB;
        c1 = getSize(refA);
        c2 = getSize(refB);
        int d = 0;
        if(c1>c2){
            d = c1-c2;
            return interesectHelper(refA,refB,d);
        }else{
            d = c2-c1;
            return interesectHelper(refB, refA, d);
        }
        return nullptr;
    }
};