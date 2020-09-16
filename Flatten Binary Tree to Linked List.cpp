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
    void flatten(TreeNode* A) {
        if(A==NULL) 
    return;
    if(A->left==NULL && A->right==NULL)
    {
        return;
    }
    if(A->left!=NULL)
    {
        flatten(A->left);
        TreeNode* temp=A->right;
        A->right=A->left;
        A->left=NULL;
        TreeNode *t=A->right;
        while(t->right!=NULL)
        {
            t=t->right;
        }
        t->right=temp;
    }
    flatten(A->right);
    }
};
