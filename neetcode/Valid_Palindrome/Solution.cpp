class Solution {
public:
    bool isPalindrome(string s) {
        // Two pointers one at each end of string, move them towards each other and check if chars they point to match
        int L = 0;
        int R = s.size() - 1;
        while(L < R)
        {
            while(L < R && !isalnum(s[L])) {L++;}
            while(R > L && !isalnum(s[R])) {R--;}
            if(tolower(s[L]) != tolower(s[R]))
            {
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};
