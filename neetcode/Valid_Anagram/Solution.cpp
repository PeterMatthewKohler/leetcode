class Solution {
public:
    bool isAnagram(string s, string t) {
        // Edge case: strings are unequal size
        if(s.size() != t.size()){return false;}
       std::unordered_map<char, int> map1, map2;
       // Construct hash maps containing the count of chars in each string
       for(auto elem : s)
       {
        // First entry
        if(map1.find(elem) == map1.end())
        {
            // Add to map
            map1[elem] = 1;
        }
        // Already an entry
        else
        {
            map1[elem]++;
        }
       } 
       for(auto elem : t)
       {
        // First entry
        if(map2.find(elem) == map2.end())
        {
            map2[elem] = 1;
        }
        else
        {
            map2[elem]++;
        }
       }
       // Traverse the map checking that the key value pairs match
       for(auto itr : map1)
       {
        if(itr.second != map2[itr.first]){return false;}
       }
       // Valid anagram
       return true;
    }
};
