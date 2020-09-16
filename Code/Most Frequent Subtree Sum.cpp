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
    int sum(TreeNode* root, unordered_map<int, int>& rec)
    {
        if(!root)
            return 0;
        int s = root->val + sum(root->left, rec) + sum(root->right, rec);
        rec[s]++;
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> rec;
        sum(root, rec);
        int freq = 0;
        for(auto i : rec)
        {
            freq = max(freq, i.second);
        }
        vector<int> res;
        for(auto i : rec)
        {
            if(i.second == freq)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
