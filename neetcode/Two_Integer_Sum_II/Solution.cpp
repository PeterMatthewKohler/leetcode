class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Edge case: only 2 numbers
        if(numbers.size() == 2){return {1, 2};}
        int L = 0; int R = numbers.size() - 1;
        while(numbers[L] + numbers[R] != target) // Ok since there must be a valid soln
        {
            int diff = target - (numbers[L] + numbers[R]);
            if(diff < 0){R--;} // Too big, need to go smaller, decrement R
            else if(diff > 0){L++;} // Too small, increment L
        } 
        return {L+1, R+1}; // One-based indexing
    }
};

