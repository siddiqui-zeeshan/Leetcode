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
    int maximum(TreeNode* root, int mx, int mn)
    {
        if(root==NULL)
            return mx-mn;
        mx=max(mx, root->val);
        mn=min(mn, root->val);
        return max(maximum(root->left, mx, mn), maximum(root->right, mx, mn));
    }
    int maxAncestorDiff(TreeNode* root) {
        return maximum(root, 0, INT_MAX);
    }
};
