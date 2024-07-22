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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 or !l2){
            return l1?l1:l2;
        };
        if(l1->val > l2->val){
            ListNode* head = new ListNode(l2->val);
            head->next = mergeTwoLists(l1,l2->next);
            return head;
        };
        ListNode* head = new ListNode(l1->val);
        head->next = mergeTwoLists(l1->next,l2);
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return NULL;
        for(int i = 1;i<lists.size();i++){
            lists[i] = mergeTwoLists(lists[i-1],lists[i]);
        }
        return lists.back();
    }
};