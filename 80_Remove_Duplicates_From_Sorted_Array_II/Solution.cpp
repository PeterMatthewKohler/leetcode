class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // Handle cases with 0, 1, or 2 elements
        
        int L = 2; // Position to place the next valid number (start at index 2)
        for (int R = 2; R < nums.size(); R++) {
            // Include nums[R] if it's different from the number two positions back
            if (nums[R] != nums[L-2]) {
                nums[L] = nums[R];
                L++;
            }
        }
        return L;
    }
};
