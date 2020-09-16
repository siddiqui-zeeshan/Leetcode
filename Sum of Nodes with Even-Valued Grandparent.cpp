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
    int sum(TreeNode* root, int gp, int p)
    {
        if(!root)
            return 0;
        int s = 0;
        if(gp > 0 && gp % 2 == 0)
            s += root->val;
        gp = p;
        p = root->val;
        s += sum(root->left, gp, p) + sum(root->right, gp, p);
        return s;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return sum(root, -1, -1);
    }
};
