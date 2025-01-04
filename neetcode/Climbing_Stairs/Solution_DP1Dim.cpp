class Solution {
public:
    // Dynamic Programming 1D Solution
    // Use a cache to store the work we've already done and then traverse top-down using DFS
    unordered_map<int,int> cache;
    int dfs(int n, unordered_map<int,int>* cache)
    {
        // Recursion base case
        if(n == 0)
        {
            return 1;
        }
        if(n < 0){return 0;}
        // If we've already done this calculation
        if(cache->count(n))
        {
            return(*cache)[n];
        }
        // If we haven't done this calculation yet
        (*cache)[n] = dfs(n - 1, cache) + dfs(n - 2, cache);
        return (*cache)[n];
    }
    int climbStairs(int n) {
        return dfs(n, &cache);
    }
};
