class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Define our indices
        int L = 0;
        int R = nums.size() - 1;
        int mid;
        // Perform the search
        while(L <= R)
        {
            mid = (L + R)/2;
            if(target > nums[mid])
            {
                // Shift the left index to one past the middle
                L = mid+1;
            }
            else if(target < nums[mid])
            {
                // Shift the right index to one before the middle
                R = mid-1;
            }
            else
            {
                // We've found the target
                return mid;
            }
        }
        // If we leave the while loop, the target doesn't exist
        return -1;
    }
};
