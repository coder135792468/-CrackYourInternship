class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums,int low = -1, int high = -1) {
        if(low > high)return NULL;
        if(low == -1 and high == -1){
            low = 0, high = nums.size()-1;
        };
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums,low,mid-1);
        root->right = sortedArrayToBST(nums,mid+1,high);
        return root;
    }
};