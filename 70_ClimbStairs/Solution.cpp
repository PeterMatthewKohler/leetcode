class Solution {
public:
    // Number of unique paths
    int dp(int curr, int total, std::vector<int>& cache)
    {
        // Recursion base case: overshoot
        if(curr > total){return 0;}
        // Recursion base case: match
        if(curr == total){return 1;}
        // Dynamic programming
        if(cache[curr] != -1){return cache[curr];}
        // Update our cache
        return cache[curr] = dp(curr+1, total, cache) + dp(curr+2, total, cache);
    }

    int climbStairs(int n) {
        std::vector<int> cache(n, -1);
        return dp(0, n, cache);
    }
};
