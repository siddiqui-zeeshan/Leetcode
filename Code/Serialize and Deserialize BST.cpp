/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    vector<int> split(string s)
    {
        vector<int> res;
        string w = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ',')
            {
                w += s[i];
            }
            else
            {
                res.push_back(stoi(w));
                w = "";
            }
        }
        return res;
    }
    string inorder(TreeNode* root)
    {
        if(!root)
            return "";
        string res = "";
        res += to_string(root->val) + ",";
        res += inorder(root->left);
        
        res += inorder(root->right);
        return res;
    }
    TreeNode* helper(vector<int> v,int s,int e)
    {
        if(s>=e)
            return NULL;
        TreeNode* x=new TreeNode(v[s]);
        int idx=s;
        while(idx<e&&v[s]>=v[idx])
            idx++;
        x->left=helper(v,s+1,idx);
        x->right=helper(v,idx,e);
        return x;
    }
    string serialize(TreeNode* root) {
        string res = inorder(root);
        //cout<<res<<" ";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> tree;
        tree = split(data);
        TreeNode* root = helper(tree, 0, tree.size());
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
