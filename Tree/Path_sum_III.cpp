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
    map<long long,long long> mp;
    long long cnt = 0;
    void helper(TreeNode *root,long long k,long long sum = 0){
        if(!root)return;
        sum+=root->val;
        if(mp[sum - k])cnt+=mp[sum - k];
        mp[sum]++;
        helper(root->left,k,sum);
        helper(root->right,k,sum);
        mp[sum]--;
    }
  
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        helper(root,targetSum*1LL);
        return cnt;
    }
};