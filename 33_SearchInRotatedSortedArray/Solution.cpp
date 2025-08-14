class Solution {
public:

    // Binary search impl.
    int binarySearch(vector<int> nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target){return mid;}
            else if(nums[mid] >= target){right = mid - 1;} // Pull right down
            else{left = mid + 1;} // Push left up
        }
        return -1;
    }

    // Use binary search to find the pivot, then use binary search to find the value
    int search(vector<int>& nums, int target) {
        // Find the pivot that separates the non-rotated from the rotated portion
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r)/2;
            if(nums[mid] > nums[r]){l = mid + 1;} //
            else{r = mid;} // In the rotated portion
        }
        // Pivot is l(?)
        int pivot = l;
        // Now do binary search based on which section of the sorted array our target SHOULD be if it exists
        if(target > nums[nums.size()-1]) // Search from left to pivot-1
        {
            return binarySearch(nums, target, 0, pivot-1);
        }
        else
        {
            return binarySearch(nums, target, pivot, nums.size()-1); // Search from pivot to right
        }
    }
};
