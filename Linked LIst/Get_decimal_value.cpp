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
    int getDecimalValue(ListNode* head) {
         int res = 0;
         int len = 0;
         ListNode* temp = head;
         while(temp){
            ++len;
            temp = temp->next;
         }
         --len;
         while(head){
            if(head->val){
                res |= (1<<len);
            }
            len--;
            head=head->next;
         }
         return res;
    }
};