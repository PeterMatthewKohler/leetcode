class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Dynamic programming solution
        // cache solution of min clips needed to get up to dp[idx]
        const int max = 1e5; // Something outside of the possible range
        std::vector<int> dp(time+1, max);   // zero -> time
        // We need zero clips to reach time 0
        dp[0] = 0;
        // Iterate from 1 to time, going through clips checking to see if
        // we can use previous cached value to get to time in less clips than
        // what we've found so far
        for(int t = 1; t <= time; t++) {
            for(const auto& clip : clips) {
                int start = clip[0], end = clip[1];
                // Can this clip fill the gap from start to t?
                if(start < t && t <= end){dp[t] = min(dp[t], dp[start]+1);}
            }
        }
        return dp[time] == max ? -1 : dp[time];
    }
};
