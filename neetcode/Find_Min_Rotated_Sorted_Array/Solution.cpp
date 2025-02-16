class Solution {
public:
    int findMin(vector<int> &nums) {
        int L = 0;
        int R = nums.size() - 1;
        // Trying to find point where L > R
        while (L < R)
        {
            int mid = L + ((R - L) / 2);
            if(nums[mid] < nums[R])
            {
                R = mid;
            }
            else
            {
                L = mid + 1;
            }
        }
        return nums[L];
    }
};
