class Solution {
public:
    int findMin(vector<int>& nums) {
        // Use binary search
        int l = 0, r = nums.size() - 1;
        while(l < r) // Keep going until l == r
        {
            int mid = (l + r) / 2;
            // Which sorted array are we in? Left or right?
            if(nums[mid] < nums[r]) // In right sorted array
            {
                r = mid; // min could be mid, so don't go past it
            }
            else // Left sorted array
            {
                l = mid + 1; // We can go one past mid since mid is not less than r
            }
        }
        return nums[l];
    }
};
