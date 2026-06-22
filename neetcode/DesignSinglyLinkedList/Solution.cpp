class LinkedList {
public:
    struct ListNode {
        int val_;
        ListNode* next_;
        ListNode(int x) : val_(x), next_(nullptr) {};
    };

    ListNode* head_;
    ListNode* tail_;
    LinkedList() {
        head_ = nullptr;
        tail_ = head_;
    }

    // Cleanup destructor
    ~LinkedList() {
        ListNode* curr = head_;
        // Cleanup the list
        while(curr) {
            ListNode* next = curr->next_;
            delete curr;
            curr = next;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }

    int get(int index) {
        if(!head_){return -1;}
        ListNode* curr = head_;
        for(int i = 0; i < index; i++) {
            if(curr->next_){curr = curr->next_;}
            else{return -1;}
        }
        return curr->val_;
    }

    void insertHead(int val) {
        if(!head_){
            head_ = new ListNode(val);
            tail_ = head_;
        }
        else{
            ListNode* tmp = new ListNode(val);
            tmp->next_ = head_;
            head_ = tmp;
        }
    }
    
    void insertTail(int val) {
        // If list is empty
        if(!tail_){
            tail_ = new ListNode(val);
            head_ = tail_;
        }
        else {
            tail_->next_ = new ListNode(val);
            tail_ = tail_->next_;
        }

    }

    bool remove(int index) {
        if (index < 0 || !head_) {
            return false;
        }

        // Remove head
        if (index == 0) {
            ListNode* nodeToDelete = head_;
            head_ = head_->next_;

            if (!head_) {
                tail_ = nullptr;
            }

            delete nodeToDelete;
            return true;
        }

        // Move to node before the one we want to remove
        ListNode* prev = head_;
        for (int i = 0; i < index - 1; i++) {
            if (!prev->next_) {
                return false;
            }
            prev = prev->next_;
        }

        // index is out of bounds
        if (!prev->next_) {
            return false;
        }

        ListNode* nodeToDelete = prev->next_;
        prev->next_ = nodeToDelete->next_;

        if (nodeToDelete == tail_) {
            tail_ = prev;
        }

        delete nodeToDelete;
        return true;
    }

    vector<int> getValues() {
        std::vector<int> res;
        ListNode* curr = head_;
        while(curr) {
            res.push_back(curr->val_);
            curr = curr->next_;
        }
        return res;
    }
};
