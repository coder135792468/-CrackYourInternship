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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* list = new ListNode(-1);
        ListNode* list_head = list;
        while(head){
            int val = head->val;
            int cnt = 0;
            while(head and head->val == val)head = head->next,++cnt;
            if(cnt == 1){
                list->next = new ListNode(val);
                list = list->next;
            }
        }
        return list_head->next;
    }
};