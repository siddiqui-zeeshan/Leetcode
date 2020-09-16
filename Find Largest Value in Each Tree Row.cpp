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
    
    void level(TreeNode* A, int n, set<int, greater <int>>& rec)
    {
        if(n==0 || A==NULL)
        return;
        if(n==1)
        {
            rec.insert(A->val);
        }
        level(A->left,n-1, rec);
        level(A->right,n-1, rec);
        return;
    }
    
    vector<int> largestValues(TreeNode* A) {
        int h=height(A);
        set<int, greater<int>> rec;
        vector<int> res;
        for(int i=1; i<=h;i++)
        {
            level(A, i, rec);
            auto j=rec.begin();
            res.push_back(*j);
            rec.clear();
        }
        return res;
    }
};
