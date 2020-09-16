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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> m;
        int sum = 0;
        ListNode* temp = head;
        while(temp)
        {
            sum += temp->val;
            if(sum == 0)
            {
                head = temp->next;
                temp = temp->next;
                m.clear();
                
            }
            else if(m.find(sum) != m.end())
            {
                ListNode* left = m[sum];
                ListNode* c = left->next;
                int nsum = sum;
                while(c != temp)
                {
                    nsum += c->val;
                    m.erase(nsum);
                    c = c->next;
                }
                ListNode* right = temp->next;
                left->next = right;
                temp = right;
            }
            else if(m.find(sum) == m.end())
            {
                m[sum] = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
