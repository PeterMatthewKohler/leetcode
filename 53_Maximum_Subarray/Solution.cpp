class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algo
        int currSum = 0;
        int maxSum = nums[0];
        for(auto num : nums)
        {
            if(currSum < 0){currSum = 0;} // Reset
            currSum += num;
            maxSum = std::max(maxSum, currSum);
        }
        return maxSum;
    }
};
