class Solution {
public:

    int dp(string& text1, string& text2, int idx1, int idx2)
    {
        // Recursion base case(s):
        if(idx2 == text2.size() || idx1 == text1.size()){return 0;}

        // Recursion
        // We have matching characters
        if(text1[idx1] == text2[idx2])
        {
            return 1 + dp(text1, text2, idx1 + 1, idx2 + 1);
        }
        return max(dp(text1, text2, idx1 + 1, idx2),
                   dp(text1, text2, idx1, idx2 + 1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return dp(text1, text2, 0, 0);
    }
};
