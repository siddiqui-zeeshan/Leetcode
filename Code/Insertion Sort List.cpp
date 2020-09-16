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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* headTemp = new ListNode();
        int num = head->val;
        ListNode* n1 = new ListNode(num);
        headTemp->next = n1;
        n1->next = NULL;
        
        ListNode* t1 = head;
        head = new ListNode();
        while(t1->next)
        {
            int x = t1->next->val;
            head = headTemp;
            while(head)
            {
                if((head->next && x <= head->next->val) || head->next == NULL)
                {
                    ListNode* temp = new ListNode(x);
                    temp->next = head->next;
                    head->next = temp;
                    break;
                }
                
                head = head->next;
            }
            t1 = t1->next;
        }
    return headTemp->next;
        
    }
};
