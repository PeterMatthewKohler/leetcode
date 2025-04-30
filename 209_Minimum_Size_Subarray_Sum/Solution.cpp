class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int sum = nums[0];
        int retLen = 0;
        int R = 0;
        while(R < nums.size())
        {
            // If sum >= target, we increment L, if not we increment R
            if(sum >= target)
            {
                if(retLen == 0){retLen = (R - L + 1);} // First window found
                else{retLen = min(retLen, R - L + 1);} // Multiple found, choose smallest
                // Remove L ptr num and increment
                sum -= nums[L];
                L++;
            }
            else // Less than target
            {
                R++;
                if(R < nums.size()){sum += nums[R];}
            }
        }
        return retLen;
    }
};
