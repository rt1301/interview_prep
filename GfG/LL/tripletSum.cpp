/****
 * Given three linked lists, say a, b and c, 
 * find one node from each list such that the sum of the values of the nodes 
 * is equal to a given number.For example, if the three linked lists 
 * are 12->6->29, 23->5->8 and 90->20->59, and the given number is 101, 
 * the output should be tripel “6 5 90”.
 ****/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*next;
    int data;
};
bool isSumSorted(Node*l1,Node*l2,Node*l3,int sum){
    Node*a = l1;
    while(a){
        Node*b = l2;
        Node*c = l3;
        while (b && c)
        {
            int s = a->data + b->data + c->data;
            if(s == sum){
                cout<<"Triplet Found: "<<a->data<<" "<<b->data<<" "<<c->data;
                return true;
            }

            if(s<sum){
                // Sum is smaller so look for bigger values in b
                b = b->next;
            }else{
                // Sum is bigger so look for smaller values in c
                c = c->next;
            }
        }
        a = a->next;
    }
    cout<<"No Triplet is found";
    return false;
}
void push (Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node();
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
}
int main(){
    /* Start with the empty list */
    Node* headA = NULL; 
    Node* headB = NULL; 
    Node* headC = NULL; 
  
    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20); 
    push (&headA, 4); 
    push (&headA, 15); 
    push (&headA, 10); 
  
    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10); 
    push (&headB, 9); 
    push (&headB, 4); 
    push (&headB, 2); 
  
    /*create another sorted 
    linked list 'c' 8->4->2->1 */
    push (&headC, 1); 
    push (&headC, 2); 
    push (&headC, 4); 
    push (&headC, 8); 
  
    int givenNumber = 25; 
  
    isSumSorted (headA, headB, headC, givenNumber); 
  
    return 0; 
}