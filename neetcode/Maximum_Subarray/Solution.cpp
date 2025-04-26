class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for (auto num : nums)
        {
            if(currSum < 0){currSum = 0;} // Reset
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
