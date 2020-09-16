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
    int NO_OF_CHARS;
    int ans = 0;
    bool canFormPalindrome(string str) 
    { 
        int count[256] = {0}; 
   
        for (int i = 0; str[i];  i++) 
            count[str[i]]++; 
   
        int odd = 0; 
        for (int i = 0; i < 256; i++) 
        { 
            if (count[i] & 1) 
                odd++; 
  
            if (odd > 1) 
                return false; 
        } 
        return true; 
    } 
    void dfs(TreeNode* root, string path)
    {
        if(!root)
        {
            return;
        }
        path = path + to_string(root->val);
        if(!root->left && !root->right)
        {
            if(canFormPalindrome(path)){
                ans++;
                //cout<<path<<endl;
            }
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        NO_OF_CHARS = 256;
        dfs(root, "");
        return ans;
    }
};
