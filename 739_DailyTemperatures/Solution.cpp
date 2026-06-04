class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Edge case: 1 value
        if(temperatures.size() == 1){return {0};}
        // Monotonic decreasing stack, store the indices of the days
        // because the answer is the difference between days
        std::stack<int> stack;
        std::vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            if(stack.empty() || temperatures[i] <= temperatures[stack.top()]){stack.push(i);}
            else {
                while(!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                    int prev_day = stack.top();
                    res[prev_day] = i - prev_day;
                    stack.pop();
                }
                stack.push(i);
            }
        }
        return res;
    }
};
