class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Calculate the total of the array
        int total = 0;
        for(auto num : nums){total += num;}
        // rightSum = total - leftSum - nums[i]
        int leftSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int rightSum = total - leftSum - nums[i];
            if(rightSum == leftSum){return i;}
            leftSum += nums[i];
        }
        return -1;
    }
};
