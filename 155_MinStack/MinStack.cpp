class MinStack {
public:
    std::deque<std::pair<int,int>> s;   // First is the stack value, second is the minimum up until that point
    MinStack() {

    }

    void push(int val) {
        if(s.empty())
        {
            s.push_back({val,val}); // First entry, set the min to be the input value
        }
        else
        {
            s.push_back({val, min(s.back().second, val)});  // Not first entry, compare the input value with the current minimum up
                                                            // until that point. Choose the lower of the two to set as the new min.
        }
    }

    void pop() {
        s.pop_back();
    }

    int top() {
        return s.back().first;
    }

    int getMin() {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
