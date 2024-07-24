class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> helper(Node* root){
        if(!root){
            return {INT_MAX,INT_MIN,0};
        };
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if(root->data > left[1] and root->data < right[0]){
            return {
                min(left[0], root->data) ,
                max(right[1], root->data),
                left[2] + right[2] + 1
            };
        };
        
        return {
            INT_MIN,
            INT_MAX,
            max(left[2],right[2])
        };
    }
    int largestBst(Node *root)
    {
    	return helper(root)[2];
    }
};