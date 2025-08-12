class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        int wrongSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += i;
            wrongSum += nums[i];
        }
        std::cout << sum << " " << wrongSum;
        return sum - wrongSum;
    }
};
