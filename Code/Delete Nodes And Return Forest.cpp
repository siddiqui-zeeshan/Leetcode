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
    vector<TreeNode*> res;
    void del(TreeNode* root, unordered_multiset<int> s)
    {
        if(!root)
            return;
        //cout<<root->val<<endl;
        TreeNode* l = root->left;
        if(root->left && s.find(root->left->val)!=s.end())
        {
            root->left = NULL;
        }
        del(l, s);
        TreeNode* r = root->right;
        if(root->right && s.find(root->right->val)!=s.end())
        {
            root->right = NULL;
        } 
        del(r, s);
        
        if(s.find(root->val) != s.end())
        {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            if(l)
            res.push_back(l);
            if(r)
            res.push_back(r);
            s.erase(root->val);
            
            root->left = NULL;
            root->right = NULL;
            root = NULL;
            
            del(l, s);
            del(r, s);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        res.clear();
        unordered_multiset<int> s;
        for(int i = 0; i < to_delete.size(); i++)
        {
            s.insert(to_delete[i]);
        }
        if(s.find(root->val) == s.end())
            res.push_back(root);
        del(root, s);
        return res;
    }
};
