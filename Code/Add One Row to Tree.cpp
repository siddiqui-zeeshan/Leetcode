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
    int height(TreeNode* node)
    {
        if(node==NULL)
        return 0;
        if(node->left==NULL && node->right==NULL)
        return 1;
        int hei=1+max(height(node->left),height(node->right));
        return hei;
    }
    void level(TreeNode* root, int n, int v)
    {
        if(n==0 || root==NULL)
        return;
        if(n==2)
        {
            TreeNode *oll=root->left;
            TreeNode *olr=root->right;
            TreeNode *newl=new TreeNode(v);
            TreeNode *newr=new TreeNode(v);
            root->left=newl;
            root->right=newr;
            if(oll!=NULL)
                newl->left=oll;
            if(olr!=NULL)
                newr->right=olr;
        }
  
        level(root->left,n-1, v);
        level(root->right,n-1, v);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int h=height(root);
        if(d==1)
        {
            TreeNode *temp=new TreeNode(v);
            temp->left=root;
            return temp;
        }
        level(root, d, v);
        return root;
        
    }
};
