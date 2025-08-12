class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int start = 0;
        for(auto num : nums)
        {
            if(start != num){return start;}
            start++;
        }
        return start;
    }
};
