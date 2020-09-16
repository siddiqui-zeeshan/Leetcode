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
    int size;
    ListNode* node;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* temp = head;
        node = head;
        int n = 0;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        size = n;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* temp = node;
        
        int r = (rand() % size) + 1;
        for(int i = 1; i < r; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
