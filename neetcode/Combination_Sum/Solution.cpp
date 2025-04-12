class Solution {
public:
    // At each point in the recursion we have two paths, we can add the current number
    // to the sum, or skip that number and move on to the next. Need to explore both options
    // in each recursive call.
    vector<vector<int>> retVect; // Return object
    void backtrack(vector<int>& nums, vector<int> curr, int index, int target)
    {
        if(target == 0)
        {
            retVect.push_back(curr);
            return;
        }
        if(target < 0 || index >= nums.size()){return;}
        // Stay at current index
        curr.push_back(nums[index]);
        backtrack(nums, curr, index, target - nums[index]);
        curr.pop_back();
        // Explore the next index value
        backtrack(nums, curr, (index+1), target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<int> curr;
        backtrack(nums, curr, 0, target);
        return retVect;
    }
};
