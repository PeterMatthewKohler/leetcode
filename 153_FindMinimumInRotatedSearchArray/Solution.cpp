class Solution {
public:
    int findMin(vector<int>& nums) {
        // Find the pivot (min value in the rotated array)
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[r]) // In right rotated array, pivot could be mid or to left of mid
            {
                r = mid;
            }
            else // nums[mid] >= nums[r] In left rotated array, pivot has to be past mid to the right
            {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
