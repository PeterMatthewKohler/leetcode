class LLNode {
public:
    LLNode* prev;
    int val;
    LLNode* next;
    LLNode() {
        prev = nullptr;
        val = 0;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    LLNode* head;
    LLNode* tail;
    MyLinkedList() {
        // Create two nodes that serve as a head and tail and link them
        head = new LLNode(); // Dummy head
        tail = new LLNode(); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int index) {
        int retVal = -1;
        if (head->next != tail) // If there are actually nodes in this LL
        {
            // Traverse to the index.
            LLNode* curr = head->next; // @ index = 0 here
            int idxTrv = 0;
            while (curr->next && (idxTrv != index)) {
                curr = curr->next;
                idxTrv++;
            }
            // If we made it to the correct index
            if (idxTrv == index) {
                retVal = curr->val;
            }
        }

        return retVal;
    }

    void addAtHead(int val) {
        // Create the new node
        LLNode* node = new LLNode();
        node->val = val;
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void addAtTail(int val) {
        // Create the new node
        LLNode* node = new LLNode();
        node->val = val;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void addAtIndex(int index, int val) {
        // Traverse if there are nodes in this LL
        if (head->next != tail) {
            LLNode* curr = head->next;
            int idxTrv = 0;
            while (curr->next && (idxTrv != index)) {
                curr = curr->next;
                idxTrv++;
            }
            // If we got to the requested index
            if (idxTrv == index) {
                // Insert the new node
                LLNode* node = new LLNode();
                node->val = val;
                node->prev = curr->prev;
                node->next = curr;
                curr->prev->next = node;
                curr->prev = node;
            }
        }
    }

    void deleteAtIndex(int index) {
        // Traverse if there are nodes in the LL
        LLNode* curr = nullptr;
        int idxTrv = 0;
        if (head->next != tail) {
            curr = head->next;
        }
        while (curr->next && (idxTrv != index)) {
            curr = curr->next;
            idxTrv++;
        }
        // If we got to the requested index
        if (idxTrv == index && curr != tail) {
            LLNode* prev = curr->prev;
            LLNode* next = curr->next;
            prev->next = next;
            next->prev = prev;
        }
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
