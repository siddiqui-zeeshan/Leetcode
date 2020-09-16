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
    void recur(TreeNode* root, set<int>& s)
    {
        if(!root)
            return;
        recur(root->left, s);
        s.insert(root->val);
        recur(root->right, s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        recur(root, s);
        auto i = s.begin();
        if(s.size() <= 1)
            return -1;
        else
            return *(++i);
    }
};
