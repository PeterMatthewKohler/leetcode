class Solution {
public:
    int search(vector<int>& nums, int target) {
        // First need to find pivot point, where our sorted array begins
        // This is smallest value in array
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            // In right sorted portion, pivot can be mid or to left of mid
            if(nums[mid] < nums[r]){r = mid;}
            // In left sorted portion, pivot has to be to right of mid
            else{l = mid + 1;}
        }
        // Pivot is l ptr
        int pivot = l;
        // Now implement standard binary search to search in either portion of array
        // based on value of target
        auto binarySearch = [&nums](int l, int r, int target) {
            while(l <= r) {
                int mid = (l + r) / 2;
                if(nums[mid] == target){return mid;}    // Found it
                else if(nums[mid] > target){r = mid - 1;}   // Search left
                else{l = mid + 1;}  // Search right
            }
            return -1;  // Not in array
        };
        if(target > nums[nums.size()-1]) // Target is in left sorted portion of array
        {
            return binarySearch(0, pivot-1, target);
        }
        else    // Target is in right sorted portion of array
        {
            return binarySearch(pivot, nums.size()-1, target);
        }
    }
};
