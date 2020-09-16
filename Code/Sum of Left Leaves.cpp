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
    int s;
    void sum(TreeNode* root, char c)
    {
        if(!root)
            return;
        if(!root->left && !root->right && c == 'l')
        {
            s+= root->val;
            return;
        }
        sum(root->left, 'l');
        sum(root->right, 'r');
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        s = 0;
        sum(root, 'r');
        return s;
    }
};
