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
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while(head) {
            ListNode* tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1), l2 = reverseList(l2);
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry = 0;
        while(l1 or l2){
            int x1 = l1?l1->val:0, x2 = l2?l2->val:0;
            int sum = (x1 + x2 + carry)%10;
            carry = (x1 + x2 + carry)/10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        };
        if(carry){
            temp->next = new ListNode(carry);
        };
        return reverseList(head->next);
    }
};