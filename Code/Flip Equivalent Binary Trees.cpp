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
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if ((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){            
            return false;            
        } else if (root1!= NULL) {  
/*which means none of them is NULL, since with previous if condition we made sure both of them are NULL or none of them is NULL*/
            return ( (root1->val ==root2->val) && (
                         (flipEquiv (root1->right, root2->left) && flipEquiv (root1->left, root2->right) )  ||
                         (flipEquiv (root1->left, root2->left) && flipEquiv (root1->right, root2->right) )  )  );                           
                                
        } else 
            return true;        
    }
};
