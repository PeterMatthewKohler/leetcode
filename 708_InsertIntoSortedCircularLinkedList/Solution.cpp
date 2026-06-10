/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // Edge case: list is empty. Return new node
        if(head == nullptr){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        // Edge case: single node
        if(head->next == head) {
            head->next = new Node(insertVal, head);
            return head;
        }

        Node* curr = head;
        while(true) {
            // 3 possibilities
            // 1. Normal position in the LL: curr <= insertVal <= curr->next
            bool normal = (curr->val <= insertVal && insertVal <= curr->next->val);
            // 2. Wraparound position: curr > insertVal && insertVal < curr->next
            bool wrap = (curr->val > curr->next->val) &&
                        (insertVal >= curr->val || insertVal <= curr->next->val);
            // 3. Full loop
            bool full = curr->next == head;

            if(normal || wrap || full) {
                curr->next = new Node(insertVal, curr->next);
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
