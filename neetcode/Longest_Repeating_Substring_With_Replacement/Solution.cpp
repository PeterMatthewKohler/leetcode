class Solution {
public:
    // Window is set by window length - most frequent char in window
    // Expand window if true, shift left if not
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;
        int L = 0;
        int maxFreq = 0;
        int retVal = 0;
        for(int R = 0; R < s.size(); R++)
        {
            // Add char at right pointer
            count[s[R]]++;
            // Update max frequency
            maxFreq = max(maxFreq, count[s[R]]);
            // Update window
            // If we have too many characters we need to update 
            // to get the same char in the whole window, we shift to the left
            // otherwise, expand window(happens naturally from for loop)
            if((R - L + 1) - maxFreq > k)
            {
                count[s[L]]--; // Remove char from window count
                L++;    // Shift window
            }
            retVal = max(retVal, (R - L + 1)); // Answer is largest window we can create
        }
        return retVal;

    }
};

