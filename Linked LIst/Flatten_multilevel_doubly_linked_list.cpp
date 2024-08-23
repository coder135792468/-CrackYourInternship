/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head,Node* next = NULL) {
        if(!head)return next;
        head->next = flatten(head->child,flatten(head->next,next));
        if(head->next){
            head->next->prev= head;
        };
        head->child = NULL;
        return head;
    }
};