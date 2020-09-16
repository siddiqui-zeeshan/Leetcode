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
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int d = 0;
        for(int i = 0; i < root->children.size(); i++)
        {
            d = max(d, maxDepth(root->children[i]));
        }
        return d + 1;
    }
};
