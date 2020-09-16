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
        ListNode* h=new ListNode();
        h->val=head->val+1;
        h->next=head;
        ListNode* t1=h;
        ListNode* t2=head;
        
        while(t2!=NULL)
        {
            while(t2->next!=NULL && t2->val==t2->next->val)
            {
                t2=t2->next;
            }
            if(t1->next==t2)
            {
                t1=t1->next;
            }
            else
            {
                t1->next=t2->next;
            }
            t2=t2->next;
        }
        head=h;
        head=head->next;
        return head;
    }
};
