class Solution {
public:
    // Bottom up dynamic programming
    int numSquares(int n) {
        // Define our DP table: number of perfect squares that sum to idx in dp[idx]
        std::vector<int> dp(n+1, INT_MAX);
        // Make our list of perfect squares
        std::vector<int> sq;
        int x = 1;
        while(x*x <= n)
        {
            sq.push_back(x*x);
            x++;
        }
        // Define our base case:
        dp[0] = 0; // No perfect squares required to solve for 0
        // Solve iteratively, loop through our amount and our perfect squares
        for(int x = 1; x <= n; x++)
        {
            for(auto square : sq)
            {
                if((x - square >= 0) && dp[x-square] != INT_MAX)
                {
                    dp[x] = min(dp[x], dp[x-square]+1);
                }
            }
        }
        return dp[n]; // There will be an answer every time given that 1*n is a solution
    }
};
