class Solution {
public:
    int binarySearch(std::vector<int>& nums, int l, int r, int target)
    {
        int res = -1; // Default choice
        while(l <= r) // Looking for an exact match
        {
            int mid = (l + r) / 2;
            if(nums[mid] == target){return mid;}
            else if(nums[mid] > target){r = mid-1;} // Search left
            else{l = mid + 1;} // Search right
        }
        return res;
    }

    int search(vector<int>& nums, int target) {
        // Binary search to find the pivot(minimum element)
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[r]) // Mid is in the right rotated array, pivot can be at or to the left of mid
            {
                r = mid;
            }
            else // nums[mid] >= nums[r] Mid is in the left rotated array, pivot has to be past mid
            {
                l = mid + 1;
            }
        }
        int pivot = l;
        // Search array based on which value of target
        if(target > nums[nums.size() - 1]) // Search left rotated array
        {
            return binarySearch(nums, 0, pivot-1, target);
        }
        else // Search right rotated array
        {
            return binarySearch(nums, pivot, nums.size()-1, target);
        }
    }
};
