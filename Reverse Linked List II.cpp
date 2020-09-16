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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp=head;
        for(int i=1;i<n;i++)
        {
            temp=temp->next;
        }
        ListNode* p3=temp->next;
        //cout<<p3->val;
        temp=head;
        for(int i=1;i<m-1;i++)
        {
            temp=temp->next;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* curr = head;
        if(m!=1)
        {
            p1=temp;
            p2=temp->next;
            curr=temp->next;
        }
        else
        {
            p1=NULL;
            p2=temp;
        }
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        for(int i=m;i<=n;i++)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        temp=prev;
        //return prev;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=p3;
        //return head;
        if(m == 1)
            return prev;
            p1->next=prev;
        return head;
    }
};
