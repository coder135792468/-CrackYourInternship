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
    int widthOfBinaryTree(TreeNode* root) {
        long long int res = 1;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
             long long int mx = 0,mn = 0;
             long long int temp = q.front().second;
             int sz = q.size();
             for(int i= 0;i<sz;i++){
                auto ele = q.front().first;
                long long int k = q.front().second - temp;
                q.pop();
                if(ele->left)q.push({ele->left,2*k + 1});
                if(ele->right)q.push({ele->right,2*k + 2});
                
                if(i == 0)mn = k;
                if(i == sz - 1)mx = k;
             }
            res = max(res,mx-mn + 1);
        }
        return res;
    }
};