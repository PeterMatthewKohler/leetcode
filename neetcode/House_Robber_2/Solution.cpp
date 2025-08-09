class Solution {
public:
    int dfs(vector<int>& nums, int idx, vector<int>& cache)
    {
        // Recursion base case: end of the 'neighborhood'
        if(idx >= nums.size()){return 0;}
        // If we've already done this work
        if(cache[idx] != -1){return cache[idx];}
        // Two choices: rob current house and skip neighbor
        int rob = nums[idx] + dfs(nums, idx+2, cache);
        // Skip current house and proceed to neighbor
        int skip = dfs(nums, idx+1, cache);
        // Pick best outcome
        return cache[idx] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        // Edge case: 'neighborhood' is a single house
        if(nums.size() == 1){return nums[0];}
        vector<int> cache1(nums.size()-1, -1);
        vector<int> cache2(nums.size()-1, -1);
        // Break the circular path down into two linear paths
        vector<int>path1(nums.begin(), nums.end()-1);
        vector<int>path2(nums.begin()+1, nums.end());
        return max(dfs(path1, 0, cache1),
                   dfs(path2, 0, cache2));
    }
};
