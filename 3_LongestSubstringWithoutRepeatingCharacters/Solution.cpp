class Solution {
public:
    // Sliding window
    int lengthOfLongestSubstring(string s) {
        // Edge case: 1 or less chars
        if(s.size() == 0){return 0;}
        int l = 0;
        int r = 0;
        std::unordered_set<char> set;
        int res = 0;
        for(int r = 0; r < s.size(); r++)
        {
            // If it's a new char, we increment the window and add our char to the set
            if(set.count(s[r]) == 0)
            {
                set.insert(s[r]);
            }
            else // It's a repeat, don't add and instead start a new window
            {
                // Increment l to one past the duplicate
                while(s[l] != s[r])
                {
                    set.erase(s[l]);
                    l++;
                }
                l++;
            }
            res = max(res, static_cast<int>(set.size()));
        }
        return res;
    }
};
