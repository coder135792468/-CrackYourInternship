class Solution{
  public:
    bool isDeadEnd(Node *root,int low = 0, int high = INT_MAX)
    {
      if(!root)return 0;
      if(!root->left and !root->right){
          return ((root->data - low) == 1 and (high - root->data) == 1);
      }
      return  isDeadEnd(root->left,low,root->data) or 
              isDeadEnd(root->right,root->data, high);
    }
};