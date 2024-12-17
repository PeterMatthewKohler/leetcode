class Solution {
public:
    vector<vector<int>> retArr;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curArr;
        backtrack(nums, target, curArr, 0);
        return retArr;
    }

    void backtrack(vector<int>& nums, int target, vector<int>&cur, int i)
    {
        if(target == 0) // Valid combination recursion base case
        {
            retArr.push_back(cur);
            return;
        }
        if(target < 0 || i >= nums.size()) // Invalid combination recursion base case
        {
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(nums, target, cur, i + 1);
    }
};
