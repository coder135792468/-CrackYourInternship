/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* node,int cnt = 0){
        while(node)++cnt,node = node->next;
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int x = getLen(headA), y =getLen(headB);
        ListNode* l1 = x > y?headA:headB;
        ListNode* l2 = x > y?headB:headA;
        int diff = abs(x-y);
        while(diff--)l1 = l1->next;
        while(l1){
            if(l1 == l2)return l1;
            l1 = l1->next, l2 = l2->next;
        };
        return NULL;
    }
};