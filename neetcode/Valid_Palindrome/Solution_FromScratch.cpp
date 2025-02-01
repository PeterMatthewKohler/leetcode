class Solution {
public:
    bool isAlphaNumeric(char c)
    {
        return (c >= 'A' && c <= 'Z') ||    // Uppercase
               (c >= 'a' && c <= 'z') ||    // Lowercase
               (c >= '0' && c <= '9');      // Numeric
    }
    bool isPalindrome(string s) {
        // Edge case: string has 1 character total
        if(s.size() == 1){return true;}
        // Two pointers: one at the front, one at the back
        int front = 0;
        int back = s.size() - 1;
        while(front < back)
        {
            // Move pointers forward or back until we get a non-space character
            while((front < back) && !isAlphaNumeric(s[front])){front++;}
            while((back > front) && !isAlphaNumeric(s[back])){back--;}
            // Do the comparison (ignoring character case)
            if(std::tolower(s[front]) != std::tolower(s[back])){return false;}
            front++;
            back--;
        }
        // Made it through the whole string
        return true;
    }
};
