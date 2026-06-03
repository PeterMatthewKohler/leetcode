class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Edge case: empty input
        if(strs.empty()){return {{""}};}
        // Build a map using the sorted string as a key
        std::unordered_map<std::string, std::vector<std::string>> hMap;
        for(const auto& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            hMap[key].push_back(str);
        }
        std::vector<std::vector<std::string>> res;
        for(const auto& pair : hMap) {
            res.push_back(pair.second);
        }
        return res;
    }
};
