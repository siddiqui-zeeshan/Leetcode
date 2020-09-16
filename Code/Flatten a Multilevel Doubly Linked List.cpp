/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<Node*> ans;
    void funct(Node* head)
    {
        ans.push_back(head);
        if(head->child)
            funct(head->child);
        if(head->next) 
            funct(head->next);
    }
    Node* flatten(Node* head) {
        if(head == NULL)
            return head;
        ans.clear();
        ans.push_back(NULL);
        funct(head);
        for(int i = 1;i<ans.size()-1;i++){ 
            ans[i]->prev = ans[i-1];   
            ans[i]->next = ans[i+1];  
            ans[i]->child = nullptr;  
        }
        ans[ans.size()-1]->prev = ans[ans.size()-2];  
        ans[ans.size()-1]->next = NULL;
        ans[ans.size()-1]->child = NULL;
        return ans[1];
        
    }
};
