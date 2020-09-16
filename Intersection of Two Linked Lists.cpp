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
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode* temp = a;
        unordered_set<ListNode*> rec;
        while(temp)
        {
            rec.insert(temp);
            temp = temp->next;
        }
        temp = b;
        while(temp)
        {
            if(rec.find(temp)!=rec.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};
