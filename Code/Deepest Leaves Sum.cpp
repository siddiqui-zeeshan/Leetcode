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
    int h;
    int sum;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void Sum(TreeNode* root, int x)
    {
        if(!root)
            return;
        if(x == h)
        {
            sum += root->val;
            return;
        }
        
        Sum(root->left, x + 1);
        Sum(root->right, x + 1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        h = height(root);
        sum = 0;
        Sum(root, 1);
        return sum;
    }
};
