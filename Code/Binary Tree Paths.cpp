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
    vector<string> res;
    void addPath(TreeNode* root, string path)
    {
        path = path + "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(path);
            return;
        }
        //path = path + "->" + to_string(root->val);
        if(root->left)
        addPath(root->left, path);
        if(root->right)
        addPath(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if(!root)
            return res;
        string path = to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(path);
        }
        if(root->left)
        addPath(root->left, path);
        if(root->right)
        addPath(root->right, path);
        return res;
    }
};
