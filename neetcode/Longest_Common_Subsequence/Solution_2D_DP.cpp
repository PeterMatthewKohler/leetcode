class Solution {
public:
    vector<vector<int>> cache;

    int dp(string& text1, string& text2, int idx1, int idx2)
    {
        // Recursion base case
        if(idx1 == text1.size() || idx2 == text2.size()) {return 0;}

        // If we've already calculated this result
        if(cache[idx1][idx2] != -1){return cache[idx1][idx2];}

        // Perform the recursion
        if(text1[idx1] == text2[idx2])  // If we have a match
        {
            cache[idx1][idx2] = 1 + dp(text1, text2, idx1 + 1, idx2 + 1);
        }
        else // We don't have a match, compare substrings
        {
            cache[idx1][idx2] = max(dp(text1, text2, idx1 + 1, idx2),
                                    dp(text1, text2, idx1, idx2 + 1));
        }
        return cache[idx1][idx2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // Set up our cache
        cache.assign(text1.size(), vector<int>(text2.size(), -1));
        return dp(text1, text2, 0, 0);
    }
};
