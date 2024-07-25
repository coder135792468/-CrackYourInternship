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
    vector<string> ans;
    void helper(TreeNode* root,string s){
        if(!root)return;
        if(!root->left and !root->right){
            ans.push_back(s);
            return;
        };
        if(root->left)helper(root->left,s+"->"+to_string(root->left->val));
        if(root->right)helper(root->right,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,to_string(root->val));
        return ans;
    }
};