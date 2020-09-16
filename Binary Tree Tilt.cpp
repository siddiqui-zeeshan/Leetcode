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
    int sum = 0;
    int diff(TreeNode* root)
    {
        if(!root)
            return 0;
        int L = diff(root->left);
        int R = diff(root->right);
        sum += abs(L - R);
        return L + R + root->val;
    }
    int findTilt(TreeNode* root) {
        sum = 0;
        diff(root);
        return sum;
    }
};
