class WordDistance {
public:
    std::unordered_map<std::string, std::vector<int>> uMap_; // <str, indices>
    WordDistance(vector<string>& wordsDict) {
        for(int idx = 0; idx < wordsDict.size(); idx++) {
            uMap_[wordsDict[idx]].push_back(idx);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for(int i = 0; i < uMap_[word1].size(); i++) {
            for(int j = 0; j < uMap_[word2].size(); j++) {
                res = min(res, abs(uMap_[word1][i] - uMap_[word2][j]));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
