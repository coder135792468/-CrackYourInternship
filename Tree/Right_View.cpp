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
    vector<int> ans;
    void preOrder(TreeNode* root,int lev){
        if(!root)return;
        if(ans.size() < lev)ans.push_back(root->val);
        preOrder(root->right,lev+1);
        preOrder(root->left,lev+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        preOrder(root,1);
        return ans;
    }
};