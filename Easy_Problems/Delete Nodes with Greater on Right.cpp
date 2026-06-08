//Problem: Delete Nodes with Greater on Right
//Topic: Linked List
//Pattern: Easy

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    Node *compute(Node *head) {
        if (!head || !head->next) return head;

        head = reverse(head);

        Node* curr = head;
        int maxSoFar = curr->data;

        while (curr && curr->next) {
            if (curr->next->data < maxSoFar) {
                curr->next = curr->next->next; 
            } else {
                curr = curr->next;
                maxSoFar = curr->data;
            }
        }

        head = reverse(head);

        return head;
        
    }
};
