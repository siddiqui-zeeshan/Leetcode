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
    vector<int> inorder(TreeNode* root)
    {
        vector<int> rec;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            rec.push_back(curr->val);
            curr=curr->right;
            
        }
        return rec;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> rec=inorder(root);
        return rec[k-1];
    }
};
