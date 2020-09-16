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
    double maxVal;
    int binarytree_count_recursive(TreeNode *root, unordered_map<int, int> &rec)
    {
        if(rec.find(root->val)!=rec.end())
            return rec.find(root->val)->second;
        int count = 1;
        if (root->left != NULL) {
            count += binarytree_count_recursive(root->left, rec);
        }
        if (root->right != NULL) {
            count += binarytree_count_recursive(root->right, rec);
        }
        rec[root->val]=count;
        return count;
    }
    int treesum(TreeNode* root, unordered_map<int, int> &rec)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
        {
            if(maxVal<root->val)
                maxVal=root->val;
            return root->val;
        }   
        int sum=root->val+treesum(root->left, rec)+treesum(root->right, rec);
        double avg=(double)sum/(double)rec[root->val];
        //cout<<sum<<" "<<rec[root->val]<<" "<<avg<<" ";
        //maxVal=max(avg, maxVal);
        if(avg>maxVal)
            maxVal=avg;
        return sum;
            
    }
    double maximumAverageSubtree(TreeNode* root) {
        maxVal=0;
        unordered_map<int, int> rec;
        int n=binarytree_count_recursive(root, rec);
        int x=treesum(root, rec);
        return maxVal;
        
    }
};
