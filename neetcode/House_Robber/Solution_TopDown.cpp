class Solution {
public:
    vector<int> cache;
    int dfs(vector<int>& nums, int house)
    {
        // Recursion base case: we are at the end of the neighbor hood and there are no more houses
        if(house >= nums.size())
        {
            return 0;
        }
        // Efficiency optimmization
        if(cache[house] != -1)
        {
            return cache[house];
        }
        // Decide if we make more robbing this house + 2nd next neighbor house OR
        // skip this house and move to neighbor
        cache[house] = max(nums[house] + dfs(nums, house + 2),
                           dfs(nums, house + 1));
        return cache[house];
    }
    int rob(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        // Run the DFS starting at the beginning
        return dfs(nums, 0);
    }
};

