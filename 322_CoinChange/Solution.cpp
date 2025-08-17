class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Define our DP table: number of coins needed to reach amount 'idx' in dp[idx]
        std::vector<int> dp(amount+1, INT_MAX); // '0' + amount and then a really big number
        // Define our base case: 0 coins required to reach amount 0
        dp[0] = 0;
        // Solve iteratively going through each amount and checking each possible coin
        for(int amt = 1; amt <= amount; amt++)
        {
            for(auto coin : coins)
            {
                // Valid if our amount doesn't go below 0, and we haven't already solved
                // this portion
                if((amt - coin >= 0) && dp[amt - coin] != INT_MAX)
                {
                    dp[amt] = min(dp[amt], dp[amt - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
