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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return l1;
        //ListNode* temp=new ListNode();
        else if(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                l1->next=mergeTwoLists(l1->next, l2);
                return l1;
            }
            else
            {
                l2->next=mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
        else if(l1 && !l2)
        {
            l1->next=mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& A) {
        if(A.size()==0)
            return NULL;
        ListNode* head=A[0];
        for(int i=1;i<A.size();i++)
        {
            head=mergeTwoLists(head, A[i]);
        }
        return head;
    }
};
