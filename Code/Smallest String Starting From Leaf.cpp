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
    string ans="";
    void dfs(TreeNode* root, string& s)
    {
        if(root==NULL)
        {
            return;
        }
        s=s+(char)(root->val+'a');
        if(root->right==NULL && root->left==NULL)
        {
            reverse(s.begin(), s.end());
            if(s<ans)
                //cout<<s<<" ";
                ans=s;
            reverse(s.begin(), s.end());
        }
        dfs(root->left, s);
        dfs(root->right, s);
        s.pop_back();
        
    }
    string smallestFromLeaf(TreeNode* root) {
        ans="~";
        string s="";
        dfs(root,s);
        return ans;
    }
};
