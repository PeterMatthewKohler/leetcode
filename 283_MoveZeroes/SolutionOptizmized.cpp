class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Traverse array, keep track of idx that was last non-zero element we found
        // If we find a non-zero, we place it after last non-zero element
        int lastNonZero = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            if(nums[idx] != 0) {
                nums[lastNonZero++] = nums[idx];
            }
        }
        // All non-zero elements sorted, place zeroes until the end
        while(lastNonZero < nums.size()) {
            nums[lastNonZero++] = 0;
        }
    }
};
