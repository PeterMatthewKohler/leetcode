class LLNode
{
    public:
    LLNode* prev;
    string val;
    LLNode* next;
};

class BrowserHistory {
public:
    LLNode* head;   // Dummy nodes 
    LLNode* tail;
    LLNode* curr;   // Current position in LL
    BrowserHistory(string homepage) {
        head = new LLNode();
        tail = new LLNode();
        // Create new node containing homepage
        curr = new LLNode();
        curr->val = homepage;
        // Link the head and tail nodes
        head->next = curr;
        curr->prev = head;
        tail->prev = curr;
        curr->next = tail;
    }

    void visit(string url) {
        // Create the new node
        LLNode* node = new LLNode();
        node->val = url;
        // Update curr
        node->prev = curr;
        node->next = tail;
        curr->next = node;
        curr = node;
        // Update tail
        tail->prev = curr;
    }

    string back(int steps) {
        while(curr->prev != head &&
              steps != 0)
        {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }

    string forward(int steps) {
        while(curr->next != tail &&
              steps != 0)
        {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */