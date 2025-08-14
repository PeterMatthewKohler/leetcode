class Solution {
public:
    // Brute force solution
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Sort all the strings, then count them using a map
        // Make a copy
        std::vector<string> copy = strs;
        for(int i = 0; i < copy.size(); i++)
        {
            std::sort(copy[i].begin(), copy[i].end());
        }
        // Now count sorted strings using their keys
        std::unordered_map<std::string, vector<int>> map;
        for(int i = 0; i < copy.size(); i++)
        {
            if(map.count(copy[i]) == 0){map[copy[i]] = {i};}
            else{map[copy[i]].push_back(i);}
        }
        // Construct the final output array
        std::vector<std::vector<std::string>> res;
        for(auto pair : map)
        {
            std::vector<std::string> vect;
            for(auto idx : pair.second)
            {
                vect.push_back(strs[idx]);
            }
            res.push_back(vect);
        }
        return res;
    }
};
