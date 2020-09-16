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
    void in(TreeNode* A, int l, int r, int h, vector<vector<string>>& res)
    {
        if(A==NULL)
        return;
        int mid=(l+r)/2;
        in(A->left, l, mid-1, h+1, res);
        res[h][mid]=to_string(A->val);
        in(A->right, mid+1, r, h+1, res);
    
    return;
    }
    vector<vector<string>> printTree(TreeNode* A) {
        int h=height(A);
        
        vector<vector<string>> res;
        int w=pow(2, h)-1;
        for(int i=0;i<h;i++)
        {
            vector<string> rec;
            for(int j=0;j<w;j++)
            {
                rec.push_back("");
            }
            res.push_back(rec);
        }
        in(A, 0, w, 0, res);
        return res;
    }
};
