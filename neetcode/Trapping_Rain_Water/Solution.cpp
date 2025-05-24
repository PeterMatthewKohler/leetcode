class Solution {
public:
    int trap(vector<int>& height) {
        // Edge case: height length is 2 or less
        if(height.size() <= 2){return 0;}
        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);
        prefix[0] = height[0];
        int n = height.size() - 1;
        suffix[n] = height[n];
        for(int i = 1; i < height.size(); i++)
        {
            prefix[i] = max(prefix[i-1], height[i]);
            suffix[n - i] = max(suffix[n - i + 1], height[n - i]);
        }
        int result = 0;
        for(int i = 0; i < height.size(); i++)
        {
            result += min(prefix[i], suffix[i]) - height[i];
        }
        return result;
    }
};

