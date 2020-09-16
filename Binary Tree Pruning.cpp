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
    TreeNode* prune(TreeNode* root)
    {
        if(root==NULL)
            return NULL;
        root->left=prune(root->left);
        root->right=prune(root->right);
        if(!root->left && !root->right && root->val==0)
            root=NULL;
        return root;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        prune(root);
        return root;
    }
};
