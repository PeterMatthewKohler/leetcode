class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Edge case: strs has 1 entry in it
        if(strs.size() == 1){return {{strs[0]}};}
        // Build a map where the key is the frequency of characters, and the value is the string from strs
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(auto str : strs)
        {
            std::vector<int> count(26, 0);  // Our index is 'a' - char
            for(auto c : str)
            {
                count[(c - 'a')]++;
            }
            std::string key;
            for(int num : count)
            {
                key += std::to_string(num) + ",";
            }
            map[key].push_back(str);
        }
        // Iterate through our map and build the final output vector
        std::vector<std::vector<std::string>> res;
        for(auto pair : map)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
