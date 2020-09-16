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
    void reorderList(ListNode* head) {
        ListNode *head1, *head2;
            ListNode *preNode, *curNode;
            
            if(!head || !(head->next) )
            {
                return;
            }
            else
            {
                head1 = head;
                head2 = head->next;
                
                while(head2 && head2->next)
                {
                    head1 = head1->next;
                    head2 = (head2->next)->next;
                }
                
                head2 =head1->next; 
                head1->next =NULL;
                preNode = NULL;
                
                while(head2)
                {
                    curNode = head2->next;
                    head2->next = preNode;
                    preNode= head2;
                    head2 = curNode;
                }
                
               
                head2 = preNode;
                head1 = head;
                
                while(head2)
                {
                    curNode = head1->next;
                    head1 = head1->next = head2;
                    head2 = curNode;
                }
                
            } 
    }
};
