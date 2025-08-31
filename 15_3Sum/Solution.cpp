class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array, then look for the negative of the two sum
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            // Skip duplicates of the first value
            if(i > 0 && nums[i] == nums[i-1]){continue;}
            // Two pointer technique
            int L = i + 1;
            int R = nums.size() - 1;
            while(L < R)
            {
                int total = nums[i] + nums[L] + nums[R];
                if(total > 0){R--;} // Too big, shift R down
                else if(total < 0){L++;} // Too small, shift L up
                else // Valid triplet
                {
                    res.push_back({nums[i], nums[L], nums[R]});
                    // Skip all duplicates
                    while(L < R && nums[L] == nums[L+1]){L++;}
                    while(L < R && nums[R] == nums[R-1]){R--;}
                    // Continue searching
                    L++;R--;
                }

            }
        }
        return res;
    }
};
