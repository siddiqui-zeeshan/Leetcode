/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* A, vector<int> &res)
{
    if(A==NULL)
    return;
    res.push_back(A->val);
    preorder(A->left, res);
    preorder(A->right, res);
}

    vector<int> preorderTraversal(TreeNode* A) {
      vector<int> res;
    preorder(A, res);
    return res;

  
    }
};
