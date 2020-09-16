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
    void inorder(TreeNode* root, vector<int>& A)
    {
        if(!root)
            return;
        inorder(root->left, A);
        A.push_back(root->val);
        inorder(root->right, A);
    }
    TreeNode* sortedArrayToBST(vector<int> arr, int start, int end)  
    {  
        if (start > end)  
        return NULL;  
        int mid = (start + end)/2;  
        TreeNode *root = new TreeNode(arr[mid]);  
        root->left = sortedArrayToBST(arr, start, mid - 1);  
        root->right = sortedArrayToBST(arr, mid + 1, end);  
        return root;  
    }  
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> A;
        inorder(root, A);
        sort(A.begin(), A.end());
        return sortedArrayToBST(A, 0, A.size() - 1);
    }
};
