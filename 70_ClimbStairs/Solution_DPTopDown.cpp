class Solution {
public:
    std::vector<int> cache_;
    int dp(int n)
    {
        // Recursion base case: past 0
        if(n < 0){return 0;}
        // If we've already done this work
        if(cache_[n] != -1){return cache_[n];}
        // If we hit the bottom
        if(n == 0){return 1;}
        return cache_[n] = dp(n - 2) + dp(n - 1);
    }

    int climbStairs(int n) {
        // Dynamic Programming: Top Down
        cache_.resize(n+1, -1);
        return dp(n);
    }
};
