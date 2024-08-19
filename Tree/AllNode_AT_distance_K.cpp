/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*,TreeNode*> parent;
    unordered_map<int, bool> vis;
    void getKDownNodes(TreeNode* root,int k){
        if(!root or k<0)return;
        if(vis[root->val])return;
        if(k==0){
                vis[root->val] = 1;
                ans.push_back(root->val);
                return;
        };
        getKDownNodes(root->left,k-1);
        getKDownNodes(root->right,k-1);
    }
    void processParent(TreeNode* root){
        parent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            if(ele->left){
                parent[ele->left] = ele;
                q.push(ele->left);
            }
            if(ele->right){
                parent[ele->right] = ele;
                q.push(ele->right);
            }
        }
    }
    TreeNode* findNode(TreeNode* root,TreeNode* target){
        if(!root)return NULL;
        if(root->val == target->val)return root;
        TreeNode* left = findNode(root->left,target);
        TreeNode* right = findNode(root->right,target);
        if(left != NULL)return left;
        return right;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        processParent(root);
        TreeNode* node = findNode(root,target);
        while(node != NULL and k>=0){
            getKDownNodes(node,k);
            vis[node->val] = 1;
            node = parent[node];
            k--;
        }
        return ans;
    }
};