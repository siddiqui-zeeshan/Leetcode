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
    void inorder(TreeNode* root, unordered_map<int, int> &rec)
    {
        if(!root)
            return;
        inorder(root->left, rec);
        rec[root->val]++;
        inorder(root->right, rec);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> rec;
        inorder(root, rec);
        int num, freq;
        freq = 0;
        for(auto i : rec)
        {
            freq = max(freq, i.second);
        }
        vector<int> res;
        for(auto i : rec)
        {
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second == freq)
                res.push_back(i.first);
        }
        return res;
    }
};
