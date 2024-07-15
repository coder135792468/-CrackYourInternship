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
        if(!head or !head->next)return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
       
    }
    bool isPalindrome(ListNode* head) {
        ListNode* low = head;
        ListNode* mid = head;
        ListNode* high = head;
        while(high and high->next){
            high = high->next->next;
            mid = mid->next;
        };
        mid = reverseList(mid);
        while(mid){
            if(low->val != mid->val)return 0;
            low = low->next;
            mid = mid->next;
        }
      
        return 1;
    }
};