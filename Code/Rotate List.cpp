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
    ListNode* rotateRight(ListNode* A, int B ) {
        if(A==NULL)
            return A;
        int n=1;
    ListNode* a=A;
        
    while(a->next!=NULL)
    {
        n++;
        a=a->next;
    }
        B=B%n;
    a->next=A;
    int l=n-B;
    a=A;
    for(int i=1;i<l;i++)
    {
        a=a->next;  
    }
    A=a->next;
    a->next=NULL;
    return A;
    }
};
