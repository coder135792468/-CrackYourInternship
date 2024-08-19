/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        return to_string(root->val) + "#" + serialize(root->left) + serialize(root->right);
    }
    TreeNode* decode(stringstream& take,string res = ""){
        getline(take,res,'#');
        if(res.empty())return NULL;
        TreeNode* root = new TreeNode(stoi(res));
        root->left = decode(take);
        root->right = decode(take);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream take(data);
        return decode(take);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));