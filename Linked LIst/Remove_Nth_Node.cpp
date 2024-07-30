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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp)++len,temp = temp->next;
        int diff = len - n;
        if(diff == 0)return head->next;
        ListNode* list = head;
        for(int i = 0;i<diff-1;i++){
            list = list->next;
        };
        list->next = list->next->next;
        return head;
    }
};