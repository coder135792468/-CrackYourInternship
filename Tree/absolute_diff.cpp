/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = INT_MAX, prev = INT_MAX;
    void helper(TreeNode* root){
        if(!root)return;
        helper(root->left);
        if(prev == INT_MAX)prev = root->val;
        else res = min(res,abs(root->val - prev));
        prev = root->val;
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
         helper(root);
         return res;
    }
};