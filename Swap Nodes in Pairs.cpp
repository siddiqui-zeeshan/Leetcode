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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        while(temp && temp->next)
        {
            int t=temp->val;
            temp->val=temp->next->val;
            temp->next->val=t;
            temp=temp->next->next;
        }
        return head;
    }
};
