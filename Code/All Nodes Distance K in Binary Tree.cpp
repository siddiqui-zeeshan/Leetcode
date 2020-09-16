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
    vector<int> res;
    int k;
    void findDist(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &par, unordered_set<TreeNode*> &vis, int dis)
    {
        if(root == NULL)
            return;
        
        if(dis == k)
            res.push_back(root->val);
        
        vis.insert(root);
        if(root->left && vis.find(root->left) == vis.end())
        {
            findDist(root->left, par, vis, dis+1);
        }
        
        if(root->right && vis.find(root->right) == vis.end())
        {
            findDist(root->right, par, vis, dis+1);
        }
        
        if(par.find(root) != par.end() && vis.find(par[root]) == vis.end())
        {
            findDist(par[root], par, vis, dis+1);
        }
        
    }
    void addParent(unordered_map<TreeNode*, TreeNode*> &par, TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
        {
            par[root->left] = root;
        }
        if(root->right)
        {
            par[root->right] = root;
        }
        addParent(par, root->left);
        addParent(par, root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        k = K;
        res.clear();
        if(root==NULL)
            return res;
        unordered_map<TreeNode*, TreeNode*> par;
        addParent(par, root);
        
        unordered_set<TreeNode*> vis;
        
        findDist(target, par, vis, 0);
        
        return res;
    }
};
