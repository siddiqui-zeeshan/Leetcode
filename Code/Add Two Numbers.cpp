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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* t3=head;
        int sum, carry;
        sum=carry=0;
        while(t1 && t2)
        {
            sum=t2->val+t1->val+carry;
            carry=sum/10;
            sum=sum%10;
            t3->val=sum;
            if(t1->next || t2->next || carry==1)
            {
            t3->next=new ListNode();
            t3=t3->next;
            }
            t1=t1->next;
            t2=t2->next;
        }
        t1=t1!=NULL?t1:t2;
        while(t1)
        {
            sum=t1->val+carry;
            carry=sum/10;
            sum%=10;
            t3->val=sum;
            if(t1->next || carry!=0)
            {    
            t3->next=new ListNode();
            t3=t3->next;
            }
            t1=t1->next;
        }
        
        if(carry==1)
           t3->val=carry;
        
        return head;
    }
};
