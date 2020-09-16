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
    void level(TreeNode* A, int n, vector<int>& rec)
    {
        if(n==0 || A==NULL)
    return;
  if(n==1)
  {
  rec.push_back(A->val);
  }
  
    level(A->left,n-1, rec);
    level(A->right,n-1, rec);
  
  return;
    }
    vector<int> rightSideView(TreeNode* A) {
        int h=height(A);
        vector<int> rec;
        vector<int> res;
        for(int i=1; i<=h;i++)
        {
            level(A, i, rec);
            res.push_back(rec[rec.size()-1]);
            rec.clear();
        }
        return res;
    }
};
