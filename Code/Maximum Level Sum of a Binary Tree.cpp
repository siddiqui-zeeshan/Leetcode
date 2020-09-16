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
    void sum(TreeNode* root, map<int, int>& lsum, int level)
    {
        if(!root)
            return;
        lsum[level] += root->val;
        sum(root->left, lsum, level + 1);
        sum(root->right, lsum, level + 1);
    }
    
    int maxLevelSum(TreeNode* root) {
        map<int, int> lsum;
        sum(root, lsum, 1);
        int level = 1;
        int s = lsum[1];
        for(auto i : lsum)
        {
            if(s < i.second)
            {
                //cout<<i.first<<" "<<i.second<<endl;
                s = i.second;
                level = i.first;
            }
        }
        return level;
    }
};
