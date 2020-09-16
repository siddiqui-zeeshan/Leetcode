/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorder(Node* root, vector<int>& rec)
    {
        if(!root)
            return;
        
        for(int i = 0; i < root->children.size(); i++)
        {
            preorder(root->children[i], rec);
        }
        rec.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> rec;
        preorder(root, rec);
        return rec;
    }
};
