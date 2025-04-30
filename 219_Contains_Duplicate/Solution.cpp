class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Edge case: k = 0
        if(k == 0){return false;} // Can't have duplicates if the window size is less than 1
        // Edge case: array is size 1 or less
        if(nums.size() < 2){return false;}
        std::unordered_set<int> window;
        int L = 0;
        for(int R = 0; R < nums.size(); R++)
        {
            if(R - L > k)
            {
                window.erase(nums[L]);
                L++;
            }
            if(window.count(nums[R]) > 0)
            {
                return true;
            }
            window.insert(nums[R]);
        }
        return false;
    }
};
