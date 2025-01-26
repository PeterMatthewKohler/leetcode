class Solution {
public:

    string encode(vector<string>& strs) {
        string retStr;
        for(auto str : strs)
        {
            retStr += std::to_string(str.size()) + "#" + str;
        }
        return retStr;
    }

    vector<string> decode(string s) {
        vector<string> retVect; // Return object
        int i = 0;
        while(i < s.size())
        {
            int j = i;
            // Get the length of the substring
            while(s[j] != '#')
            {
                std::cout << s[j] << " ";
                j++;
            }
            int length = std::stoi(s.substr(i, j-i));
            // Set indices of substring from j to i
            i = j + 1;  // i starts the substring
            j = i + length; // j ends the substring
            retVect.push_back(s.substr(i, length));
            i = j;
        }
        return retVect;
    }
};
