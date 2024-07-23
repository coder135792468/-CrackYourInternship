class Solution {
public:
    int helper(TreeNode* root,int low,int high){
        if(!root)return 0;
        int sum = 0;
        if(root->val >= low and root->val <= high)sum+=root->val;
        return sum + helper(root->left,low,high) + helper(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root,low,high);
    }
};