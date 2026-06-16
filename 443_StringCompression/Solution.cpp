class Solution {
public:
    int compress(vector<char>& chars) {
        // Two pointers, start at l and traverse until we hit non-repeating char
        // Edge case: size of 1
        if(chars.size() == 1){ 
            return 1;
        }
        // Two sets of pointers: first group to count consecutive repeating chars
        // second group to write char and count after
        int curr = 0, count = 0, write = 0;
        while(curr < chars.size()) {
            // Reset count
            count = 0;
            chars[write] = chars[curr];
            while (curr + count < chars.size() && chars[curr] == chars[curr + count]) {count++;}
            curr += count;
            // Write the count to the char after first char if count is larger than one
            std::string strLen = std::to_string(count);
            if(count != 1) {
                for(const auto& c : strLen){chars[++write] = c;}
            }
            write++;
        }
        return write;
    }
};
