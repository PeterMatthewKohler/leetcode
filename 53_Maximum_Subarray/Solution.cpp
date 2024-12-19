class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Solve with Kadane's algorithm
        int maxSum = 0;
        int curSum = 0;

        for(auto n : nums)
        {
            curSum = max(curSum, 0);
            curSum += n;
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};
