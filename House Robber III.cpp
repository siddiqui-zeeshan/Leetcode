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
    int sum(TreeNode* root, unordered_map<TreeNode*,int> &rec)
    {
        if(!root)
            return 0;
        if(rec.find(root)!=rec.end())
            return rec[root];
        int n = 0;
        if(root->left)
        {
             n += sum(root->left->left, rec) + sum(root->left->right, rec);
        }
        if(root->right)
        {
            n += sum(root->right->left, rec) + sum(root->right->right, rec);
        }
        
        n = max(n + root->val, sum(root->left, rec) + sum(root->right, rec));
        rec[root] = n;
        return n;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> rec;
        int n = sum(root, rec);
        return n;
    }
};
