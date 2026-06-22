class Deque {
public:
    struct ListNode {
        int val_;
        ListNode* prev_;
        ListNode* next_;
        // Constructor
        ListNode(int val) : val_(val), prev_(nullptr), next_(nullptr) {};
    };

    // Pointers to head and tail
    ListNode* head_;
    ListNode* tail_;

    Deque() {
        head_ = nullptr;
        tail_ = head_;
    }

    bool isEmpty() {
        if(!head_){return true;}
        else{return false;}
    }

    void append(int value) {
        // Edge case, empty queue
        if(!head_){
            head_ = new ListNode(value);
            tail_ = head_;
            return;
        }
        // Append to right side
        ListNode* tmp = new ListNode(value);
        tail_->next_ = tmp;
        tmp->prev_ = tail_;
        tail_ = tail_->next_;
    }

    void appendleft(int value) {
        // Edge case, empty queue
        if(!head_){
            head_ = new ListNode(value);
            tail_ = head_;
            return;
        }
        // Append to the left side
        ListNode* tmp = new ListNode(value);
        head_->prev_ = tmp;
        tmp->next_ = head_;
        head_ = head_->prev_;
    }

    int pop() {
        int val = -1;
        if(tail_){
            ListNode* curr = tail_;
            val = curr->val_;
            if(tail_->prev_){
                tail_ = tail_->prev_;
                tail_->next_ = nullptr;
            }
            else{tail_ = nullptr; head_ = tail_;}
            delete curr;
        }
        return val;
    }

    int popleft() {
        int val = -1;
        if(head_){
            ListNode* curr = head_;
            val = curr->val_;
            if(head_->next_){
                head_ = head_->next_;
                head_->prev_ = nullptr;
            }
            else{head_ = nullptr; tail_ = head_;}
            delete curr;
        }
        return val;
    }
};
