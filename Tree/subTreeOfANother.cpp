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
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(root == NULL and subRoot==NULL)return true;
        if(root == NULL or subRoot==NULL)return false;
        if(root->val == subRoot->val){
           return helper(root->left,subRoot->left) and helper(root->right,subRoot->right);
        }
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        return helper(root,subRoot) or isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};