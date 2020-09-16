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
    void inorder(TreeNode* root, vector<int>& rec)
    {
        if(!root)
            return;
        inorder(root->left, rec);
        rec.push_back(root->val);
        inorder(root->right, rec);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> rec;
        inorder(root, rec);
        int diff = INT_MAX;
        for(int i = 0; i < rec.size() - 1; i++)
        {
            diff = min(diff, rec[i + 1] - rec[i]);
        }
        return diff;
    }
};
