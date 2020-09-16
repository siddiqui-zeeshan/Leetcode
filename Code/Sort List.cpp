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
    ListNode* partition(ListNode* head){
        if(!head or !head->next) return head;
        ListNode* fast = head->next, *slow = head;
        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        return second;
    }
    ListNode* merge(ListNode *a, ListNode *b){
        ListNode* c = NULL;
        if(!a) return b;
        if(!b) return a;
        if(a->val < b->val) c = a;
        else{
            c = b;
            b = a;
            a = c;
        }
        while(a->next){
            if(a->next->val > b->val){
                ListNode* temp = a->next;
                a->next = b;
                b = temp;
            }
            a = a->next;
        }
        a->next = b;
        return c;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* second = partition(head);
        head = sortList(head);
        second = sortList(second);
        return merge(head, second);
    }
};
