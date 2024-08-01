class Solution {
public:
    TreeNode *prev=NULL,*first=NULL,*second=NULL;
    void inorder(TreeNode* root){
        if(root==NULL)
            return ;
        inorder(root->left);
        if(prev!=NULL&&root->val<prev->val){
            if(first==NULL) first=prev;
            second=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)  return ; 
        inorder(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};
