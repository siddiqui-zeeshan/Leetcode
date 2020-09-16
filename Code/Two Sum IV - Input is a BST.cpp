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
    stack <TreeNode*> sl, sr;
    
    void inleft(TreeNode* node)
    {
        while(node)
        {
            sl.push(node);
            node = node->left;
        }
    }
    void inright(TreeNode* node)
    {
        while(node)
        {
            sr.push(node);
            node = node->right;
        }
    }
    int nextleft()
    {
        TreeNode* curr = sl.top();
        sl.pop();
        int num = curr->val;
        inleft(curr->right);
        return num;
    }
    int nextright()
    {
        TreeNode* curr = sr.top();
        sr.pop();
        int num = curr->val;
        inright(curr->left);
        return num;
    }
    bool findTarget(TreeNode* root, int k) {
        //sl.clear();
        //sr.clear();
        TreeNode* rl = root;
        TreeNode* rr = root;
        inleft(rl);
        inright(rr);
        //cout<<sl.size()<<" "<<sr.size()<<endl;
        int l = nextleft();
        int r = nextright();
        //cout<<l<<" "<<r<<" "<<l + r<<endl;
        while(l < r)
        {
            if(l + r == k)
                return true;
            if(l + r < k)
            {
                l = nextleft();   
            }
            else
            {
                r = nextright();
            }
        }
        return false;
    }
};
