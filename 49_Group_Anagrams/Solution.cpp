class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;
        for(auto str : strs)
        {
            string word = str;
            std::sort(word.begin(), word.end());
            if(map.find(word) != map.end())
            {
                map[word].push_back(str);
            }
            else
            {
                map.insert({word, {str}});
            }
        }
        vector<vector<string>> retVect;
        for(auto itr : map)
        {
            retVect.push_back(itr.second);
        }
        return retVect;
    }
};
