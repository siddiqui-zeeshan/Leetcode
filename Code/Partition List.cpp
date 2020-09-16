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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1=new ListNode(0);
        ListNode* ph1=p1;
        ListNode* p2=new ListNode(0);
        ListNode* ph2=p2;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                p1->next=head;
                p1=p1->next;
            }
            else
            {
                p2->next=head;
                p2=p2->next;
            }
            head=head->next;
        }
        //ph1=ph1->next;
        p2->next=NULL;
        ph2=ph2->next;
        p1->next=ph2;
        return ph1->next;
    }
};
