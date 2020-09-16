/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* t1=head;
        ListNode* t2=head;
        t2=t2->next;
        while(t2)
        {
            if(t1->val!=t2->val)
            {
                t1->next=t2;
                t1=t1->next;
                t2=t2->next;
            }
            else
                t2=t2->next;
        }
        t1->next=t2;
        return head;
    }
};
