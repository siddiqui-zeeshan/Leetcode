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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if(root == p || root == q)
            return root;
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
    
        if((l == p && r == q) || (l == q && r == p))
        {
            return root;
        }
        if(!(l && r))
            return l == NULL ? r : l;
        else return NULL;
    }
};
