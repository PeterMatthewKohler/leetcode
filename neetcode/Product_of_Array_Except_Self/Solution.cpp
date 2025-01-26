class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        vector<int> prefix(size, 0);
        vector<int> suffix(size, 0);

        // Start with the ends
        prefix[0] = 1;
        suffix[size - 1] = 1;

        // Calculate the prefixes
        for(int i = 1; i < size; i++)
        {
            prefix[i] = nums[i - 1] * prefix[i - 1];    // Prefix for each index is the previous number times the previous prefix
        }
        // Calculate the suffixes
        for(int i = size - 2; i >= 0; i--)
        {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }
        // Calculate the result
        for(int i = 0; i < size; i++)
        {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
