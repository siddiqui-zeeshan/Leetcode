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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* etemp = even;
        ListNode* otemp = odd;
        int i = 1;
        while(head)
        {
            ListNode* temp = head;
            if(i % 2 == 0)
            {
                etemp ->next = temp;
                etemp = etemp->next;
                
            }
            else
            {
                otemp -> next = temp;
                otemp = otemp->next;
                
            }
            head = head->next;
            i++;
        }
        otemp->next = NULL;
        etemp->next = NULL;
        odd = odd -> next;
        even = even -> next;
        
        otemp = odd;
        while(otemp->next)
        {
            otemp = otemp->next;
        }
        otemp->next = even;
        while(even->next)
        {
            even = even->next;
        }
        even -> next = NULL;
        
        return odd;
    }
};
