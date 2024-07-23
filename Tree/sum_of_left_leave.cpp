class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root,int left = 0) {
        if(!root)return 0;
        if(!root->left and !root->right and left){
            return root->val;
        };
        return sumOfLeftLeaves(root->left,1) + sumOfLeftLeaves(root->right,0);
    }
};