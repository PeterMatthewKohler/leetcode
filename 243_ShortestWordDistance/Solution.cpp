class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        // Two pointer solution
        int res = INT_MAX;
        // Move left pointer forward until we hit either word
        for(int l = 0; l < wordsDict.size(); l++) {
            // If we hit one of the words, look for the other one
            if(wordsDict[l] == word1) {
                int r = l+1;
                while(r < wordsDict.size()) {
                    if(wordsDict[r] == word2) {
                        res = min(res, r - l);
                    }
                    r++;
                }
            }
            if(wordsDict[l] == word2) {
                int r = l+1;
                while(r < wordsDict.size()) {
                    if(wordsDict[r] == word1) {
                        res = min(res, r - l);
                    }
                    r++;
                }
            }
        }
        return res;
    }
};
