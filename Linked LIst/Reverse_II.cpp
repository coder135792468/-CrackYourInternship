/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* node){
       if(!node or !node->next)return node;
       
       ListNode* head = reverseList(node->next);
       node->next->next = node;
       node->next = NULL;
       return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = new ListNode(-1);
        ListNode* startHead = start;
        ListNode* mid = new ListNode(-1);
        ListNode* midHead = mid;
        ListNode* end = new ListNode(-1);
        ListNode* endHead = end;

        ListNode* temp = head;
        for(int i = 0;i<left-1 and temp;i++){
            start->next = new ListNode(temp->val);
            temp = temp->next;
            start = start->next;
        };
        for(int i = left;i<=right and temp;i++){
            mid->next = new ListNode(temp->val);
            temp = temp->next;
            mid = mid->next;
        };
        for(int i = right;temp!=NULL;i++){
            end->next = new ListNode(temp->val);
            temp = temp->next;
            end = end->next;
        };
        ListNode* newMid = reverseList(midHead->next);
        ListNode* tempMid = newMid;
        while(tempMid->next){
            tempMid = tempMid->next;
        }
        start->next = newMid;
        tempMid->next = endHead->next;

        return startHead->next;
    }
};