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
   ListNode* reverse(ListNode* head){
        if(!head or !head->next)return head;
        ListNode* node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
   }
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp){
            ++len;
            temp = temp->next;
        };

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        };

        slow->next = reverse(slow->next);
        slow = slow->next;
        fast = head;
        ListNode* root = new ListNode(-1);
        ListNode* rootHead = root;
        while(slow){
            root->next = new ListNode(fast->val);
            root = root->next;
            root->next = new ListNode(slow->val);
            root = root->next;
            slow = slow->next;
            fast = fast->next;
        };

        if(len&1){
            root->next = new ListNode(fast->val);
            root = root->next;
        };
        root->next = NULL;
        rootHead = rootHead->next;
        while(rootHead){
            head->next = rootHead->next;
            head = head->next;
            rootHead = rootHead->next;
        }

    }
};