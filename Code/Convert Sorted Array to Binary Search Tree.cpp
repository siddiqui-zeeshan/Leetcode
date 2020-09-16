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
    
    TreeNode* funct(vector<int>& A, int l, int r)
    {
        if(l>r)
            return NULL;
        int mid=(l+r)/2;
        TreeNode* node=new TreeNode(A[mid]);
        node->left=funct(A, l, mid-1);
        node->right=funct(A, mid+1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& A) {
        TreeNode* root=funct(A, 0, A.size()-1);
        return root;
    }
};
