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
    int res;
    void len(TreeNode* root, int l, int p)
    {
        if(!root)
            return;
        //cout<<l<<endl;
        res = max(l, res);
        if(p == 0 && !root->right)
        {
            len(root->left, 1, 0);
        }
        else if(p == 0 && root->right)
        {
            len(root->right, l + 1, 1);
            len(root->left, 1, 0);
        }
        else if(p == 1 && !root->left)
        {
            len(root->right, 1, 1);
        }
        else if(p == 1 && root->left)
        {
            len(root->right, 1, 1);
            len(root->left, l + 1, 0);
        }
        else if(p == -1)
        {
            len(root->right, 1, 1);
            len(root->left, 1, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        res = 0;
        len(root, 0, -1);
        return res;
    }
};
