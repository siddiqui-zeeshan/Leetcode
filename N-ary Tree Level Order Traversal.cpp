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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            
            for(int i = 0; i < size; i++)
            {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for(auto j : node->children)
                {
                    q.push(j);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
