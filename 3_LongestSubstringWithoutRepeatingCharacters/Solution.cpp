class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use a set to check if we have duplicates
        // Run two pointers to keep track of our current substring
        int l = 0;
        std::unordered_set<char> set;
        int res = 0; // Final result
        for(int r = 0; r < s.size(); r++)
        {
            // Two cases: char isn't a duplicate or it is
            if(set.count(s[r]) == 0) // Not a duplicate
            {
                set.insert(s[r]);
            }
            else // Duplicate
            {
                while(set.count(s[r]) != 0) // Remove old substring
                {
                    set.erase(s[l]);
                    l++;
                }
                set.insert(s[r]); // Start new one
            }
            res = std::max(res, static_cast<int>(set.size())); // Update our result
        }
        return res;
    }
};
