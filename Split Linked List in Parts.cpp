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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        int l = 0;
        ListNode* temp = root;
        while(temp)
        {
            l++;
            temp = temp->next;
        }
        ListNode* node = root;
        temp = nullptr;
        int part = l / k;
        int rem = l % k;
        for(int i = 0; node && i < k; i++, rem--)
        {
            res[i] = node;
            for(int j = 0; j < part + (rem > 0); j++)
            {
                temp = node;
                node = node->next;
            }
            temp->next = NULL;
        }
        return res;
    }
};
