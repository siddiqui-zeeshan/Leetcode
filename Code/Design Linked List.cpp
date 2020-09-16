class Node {
public:
    int val;
    Node* next;
};
class MyLinkedList {
private:
    int len;
public:
    /** Initialize your data structure here. */
    Node* node = new Node();
    MyLinkedList() {
        node->val = -1;
        node->next = NULL;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        Node* temp = node;
        index++;
        int i = 0;
        while(temp && i < index)
        {
            i++;
            temp = temp->next;
        }
        cout<<index<<" "<<len<<"\n";
        if(temp == NULL)
            return -1;
        else
            return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of 
        the linked list. */
    void addAtHead(int data) {
        
        Node* temp = new Node();
        temp->val = data;
        Node* n2 = node->next;
        node->next = temp;
        temp->next = n2;
        len++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int data) {
        Node* temp = node;
        while(temp->next)
        {
            temp = temp->next;
        }
        Node* n2 = new Node();
        n2->val = data;
        n2->next = NULL;
        temp->next = n2;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be 
        appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int data) {
        cout<<index<<" "<<len<<"\n";
        if(index > len)
            return;
        int i = 0;
        Node* temp = node;
        while(i < index)
        {
            i++;
            temp = temp->next;
        }
        Node* n2 = new Node();
        n2 = temp->next;
        Node* n = new Node();
        n->val = data;
        temp->next = n;
        n->next = n2;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        cout<<index<<" "<<len<<"\n";
        if(index >= len)
            return;
        int i = 0;
        Node* temp = node;
        while(i < index)
        {
            i++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
