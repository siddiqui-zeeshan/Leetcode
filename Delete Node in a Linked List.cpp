/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next)
        {
            int temp = node->val;
            node->val = node->next->val;
            node->next->val = temp;
            node = node->next;
        }
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;
        node->next = NULL;
    }
};
