class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set;
        int L = 0;
        int maxLen = 0;

        for(int R = 0; R < s.size(); R++)
        {
            // Erase duplicates
            while(set.find(s[R]) != set.end())
            {
                set.erase(s[L]);
                L++;
            }
            set.insert(s[R]);
            maxLen = max(maxLen, R - L + 1);
        }
        return maxLen;
    }
};
