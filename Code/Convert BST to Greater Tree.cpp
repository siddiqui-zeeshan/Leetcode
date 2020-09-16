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
    void inorder(TreeNode* root, vector<int>& rec)
    {
        if(!root)
            return;
        inorder(root->left, rec);
        rec.push_back(root->val);
        inorder(root->right, rec);
    }
    void change(TreeNode* root, vector<int>& rec, vector<int>& sum)
    {
        if(!root)
            return;
        change(root->left, rec, sum);
        int pos = find(rec.begin(), rec.end(), root->val) - rec.begin();
        int s = sum[sum.size() - 1] - (pos == 0 ? 0 : sum[pos - 1]);
        //cout<<s<<" "<<(pos == 0 ? 0 : sum[pos - 1])<<" "<<root->val<<endl;
        root->val = s;
        //cout<<s<<" "<<(pos == 0 ? 0 : sum[pos - 1])<<" "<<root->val<<endl;
        change(root->right, rec, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        vector<int> rec;
        inorder(root, rec);
        vector<int> sum(rec.size(), 0);
        sum[0] = rec[0];
        for(int i = 1; i < rec.size(); i++)
        {
            sum[i] = sum[i - 1] + rec[i];
        }
        
        change(root, rec, sum);
        return root;
    }
};
