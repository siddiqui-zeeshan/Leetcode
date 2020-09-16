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
    void level(TreeNode* A, int n, int k, int h, vector<int>& rec)
    {
        if(k==h && n==1 && A==NULL)
        {
            
            rec.push_back(INT_MAX);
        }
        if(n==0 || A==NULL)
        return;
        if(n==1)
        {
            rec.push_back(A->val);
        }
    
        level(A->left,n-1, k, h, rec);
        level(A->right,n-1, k, h, rec);
    
    return;
    }
    
    bool isCompleteTree(TreeNode* A) {
       int h=height(A);
        vector<int> rec;
        for(int i=1; i<h;i++)
        {
            level(A, i, i, h, rec);
            if(rec.size()!=pow(2,i-1))
                return false;
            rec.clear();
        } 
        
        level(A, h, h, h, rec);
        int f1=0;
        if(rec[0]==INT_MAX)
        for(int i=0;i<rec.size();i++)
        {
            if(rec[i]!=INT_MAX)
                return false;
        }
        else
            for(int i=0;i<rec.size();i++)
        {
            if(rec[i]==INT_MAX  && f1==0)
                f1++;
            if(f1==1 && rec[i]!=INT_MAX)
                return false;
        }
        return true;
    }
};
