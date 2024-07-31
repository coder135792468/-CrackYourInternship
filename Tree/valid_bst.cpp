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
    bool isValidBST(TreeNode* root,long int low = LONG_MIN, long int high =LONG_MAX) {
        if(!root)return 1;
         if(root->val >low and root->val < high){
          return  isValidBST(root->left,low, root->val) and 
                  isValidBST(root->right,root->val, high);
         } 
         return 0;
    }
};