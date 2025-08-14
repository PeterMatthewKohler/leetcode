class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Split the calculation up into two separate chunks
        // Prefix, all the calculations on the left-hand side of the pivot point
        // Suffix, all the calculations on the right-hand side of the pivot point
        std::vector<int> prefix(nums.size(), 0);
        std::vector<int> suffix(nums.size(), 0);
        // Build the arrays
        int r = nums.size() - 1;    // Suffix index
        int lSum = 1;
        int rSum = 1;
        for(int l = 0; l < nums.size(); l++)    // Prefix index
        {
            if(l > 0)
            {
                lSum *= nums[l-1];
                prefix[l] = lSum;
            }
            if(r < nums.size() - 1)
            {
                rSum *= nums[r + 1];
                suffix[r] = rSum;
            }
            r--;
        }
        // Multiply the prefix and suffix together
        std::vector<int> res(nums.size(), 0);
        res[0] = suffix[0];
        res[nums.size() - 1] = prefix[nums.size() - 1];
        for(int i = 1; i < nums.size()-1; i++)
        {
            res[i] = prefix[i]*suffix[i];
        }        
        return res;
    }
};
