class Solution {
public:
    // We want to count the total number of paths
    int dfs(string s, int idx)
    {
        // Recursion base case: at end of string
        if(idx >= s.size()){return 1;}
        if(s[idx] == '0'){return 0;}

        int result = dfs(s, idx+1);
        if(idx < s.size() - 1) // If we still have more word to go
        {
            if((s[idx] == '1') || (s[idx] == '2' && s[idx+1] < '7'))
            {
                result += dfs(s, idx+2);
            }
        }
        return result;
    }
    int numDecodings(string s) {
        return dfs(s, 0);
    }
};
