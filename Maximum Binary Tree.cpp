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
    TreeNode* construct(vector<int> &A, int l, int r)
    {
        if(l>r)
            return NULL;
        int max=l;
        for(int i=l; i<=r; i++)
        {
            if(A[i]>A[max])
                max=i;
        }
        TreeNode* root = new TreeNode(A[max]);
        root->left=construct(A, l, max-1);
        root->right=construct(A, max+1, r);
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& A) {
        TreeNode* root=construct(A, 0, A.size()-1);
        return root;
        
        
    }
};
