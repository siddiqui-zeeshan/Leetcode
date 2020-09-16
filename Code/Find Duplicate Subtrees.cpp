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
    string dfs(TreeNode* root, unordered_map<string, int>& rec, vector<TreeNode*>& res)
    {
        if(!root)
            return "";
        string seq = to_string(root->val) + "," + dfs(root->left, rec, res) + "," + dfs(root->right, rec, res);
        if(++rec[seq] == 2)
            res.push_back(root);
        return seq;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> rec;
        dfs(root, rec, res);
        return res;
    }
};
