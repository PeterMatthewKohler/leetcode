class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary search
        int L = 0;
        int R = nums.size() - 1;
        while(L <= R)
        {
            int M = (L + R) / 2;
            if(nums[M] == target){return M;}
            // Find which partition is part of the non-cut array
            if(nums[L] <= nums[M]) // Left half is non-cut
            {
                if(target > nums[M] || target < nums[L]) // Not in the non-cut section
                {
                    L = M + 1;
                }
                else
                {
                    R = M - 1;
                }
            }
            else // Right half is non-cut
            {
                if(target < nums[M] || target > nums[R])
                {
                    R = M - 1;
                }
                else
                {
                    L = M + 1;
                }
            }
        }
        return -1;
    }
};
