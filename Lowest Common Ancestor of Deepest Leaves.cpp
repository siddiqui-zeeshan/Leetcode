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
    int d;
    int depth(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    TreeNode* parent(TreeNode* root, int level)
    {
        if(!root)
            return NULL;
        if(!root->left && !root->right && level == d)
        {
            return root;
        }
        TreeNode* a = parent(root->left, level + 1);
        TreeNode* b = parent(root->right, level + 1);
        if(a && b)
            return root;
        else
            return a == NULL ? b : a;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        d = depth(root);
        return parent(root, 1);
    }
};
