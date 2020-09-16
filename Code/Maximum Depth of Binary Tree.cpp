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
    int maxDepth(TreeNode* A) {
        if(A==NULL)
    return 0;
    if(A->right==NULL && A->left==NULL)
    return 1;
    int dep=1+max(maxDepth(A->right),maxDepth(A->left));
    return dep;
    }
};
