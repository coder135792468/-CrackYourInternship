class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(!head->next)return head;
        Node* res = compute(head->next);
        if(head->data >= res->data){
            head->next = res;
            return head;
        }
        
        return res;
    }
    
};