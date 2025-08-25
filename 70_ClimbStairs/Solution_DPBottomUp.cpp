class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;              // optional early return
        std::vector<int> dp(n + 1, 0);     // dp[i] = # of ways to reach step i
        dp[0] = 1;                         // 1 way to stand at ground
        dp[1] = 1;                         // 1 way to reach step 1
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
