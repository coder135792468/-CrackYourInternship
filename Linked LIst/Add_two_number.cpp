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

   
 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);
        ListNode* rootHead = root;
        int carry = 0;
       while(l1 or l2){
            int num1 = l1?l1->val :0;
            int num2 = l2?l2->val :0;
            int num =num1+num2 + carry;
            int sum = num%10;
            num/=10;
            carry = num;
            root->next = new ListNode(sum);
            root = root->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        };
         
        if(carry)root->next = new ListNode(carry);

        return rootHead->next;
    }
};