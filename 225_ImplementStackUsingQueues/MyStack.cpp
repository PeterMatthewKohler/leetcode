class MyStack {
public:
    std::queue<int> q;
    MyStack() {
        q = {};
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for(int i = 0; i < q.size() - 1; i++)
        {
            // Pop from the queue and place at the end
            q.push(q.front());
            q.pop();
        }
        // Access the element we want, then pop
        int returnVal = q.front();
        q.pop();
        return returnVal;
    }
    
    int top() {
        // Copy the queue, and then just traverse to the end
        auto copyQ = q;
        for(int i = 0; i < q.size() - 1; i++)
        {
            copyQ.pop();
        }
        return copyQ.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
