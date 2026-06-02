class Solution {
public:
    bool isPalindrome(string s) {
        // Two pointers, one at end, one at beginning
        // Ignore non-alphanumeric characters
        int l = 0, r = s.size()-1;

        while(r > l){
            // Ignore non alphanumeric, move to first non-alphanumeric
            while(l < r && !std::isalnum(s[l])){l++;}
            while(r > l && !std::isalnum(s[r])){r--;}
            if(std::tolower(s[l]) != std::tolower(s[r])){return false;}
            l++;r--;
        }
        return true;
    }
};
