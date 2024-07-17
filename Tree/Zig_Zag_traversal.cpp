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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        int dir = 1;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           int sz = q.size();
           vector<int> res;
           for(int i = 0;i<sz;i++){
             TreeNode* temp = q.front();
               q.pop();
            res.push_back(temp->val);
            if(temp->left)q.push(temp->left);
           if(temp->right)q.push(temp->right);
           }
           if(dir == -1)
reverse(res.begin(),res.end());   
            
            ans.push_back(res);
            dir *=-1;
        }
        
        return ans;
    }
};