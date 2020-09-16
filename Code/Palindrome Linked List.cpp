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
    bool palin(ListNode** start, ListNode* end)
    {
        if(!end)
            return true;
        //palin(*start, end->next);
        if(palin(start, end->next) && (*start)->val == end->val)
        {
            *start = (*start)->next;
            return true;
        }
        else return false;
    }
    bool isPalindrome(ListNode* head) {
        return palin(&head, head);
    }
};
