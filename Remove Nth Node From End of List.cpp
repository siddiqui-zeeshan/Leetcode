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
    ListNode* removeNthFromEnd(ListNode* A, int B) {
        ListNode* temp=A;
        if(A==NULL)
            return A;
    int n=0;
    if(A->next==NULL)
    return NULL;
    while(temp!=NULL)
    {
        temp=temp->next;
        n++;
    }
    //cout<<n<<endl<<B<<endl;
    if(B>n)
    {
        A=A->next;
        return A;
    }

    n=n-B;
    if(n==0)
    {
        A=A->next;
        return A;
    }
    temp=A;
    for(int i=1;i<n;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return A;
        
    }
};
