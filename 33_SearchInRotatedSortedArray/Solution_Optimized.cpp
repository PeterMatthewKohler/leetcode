class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Use binary search
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(nums[mid] == target){return mid;}
            // Which sorted portion is mid in? Left or right?
            if(nums[l] <= nums[mid]) // Left sorted portion
            {
                // Which way do we search?
                if(target < nums[l] || target > nums[mid]) // Need to search right portion, shift l
                {
                    l = mid+1;
                }
                else // Need to search left portion
                {
                    r = mid-1;
                }
            }
            else // Right sorted portion
            {
                // Which way do we search?
                if(target < nums[mid] || target > nums[r]) // Search left
                {
                    r = mid-1;
                }
                else // Need to search right
                {
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};
