class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        std::unordered_map<std::string, std::vector<int>> uMap;  // <word, idx>
        for(int i = 0; i < wordsDict.size(); i++) {uMap[wordsDict[i]].push_back(i);}
        // Find the shortest distance between the words
        auto v1 = uMap[word1];
        auto v2 = uMap[word2];
        int res = INT_MAX;
        for(const auto& idx : v1) {
            for(const auto& idx2 : v2) {
                res = min(res, abs(idx - idx2));
            }
        }
        return res;
    }
};
