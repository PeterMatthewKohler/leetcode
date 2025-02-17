class Solution {
public:
    // Brute force
    int maxArea(vector<int>& heights) {
        int maxVal = 0;
        for(int L = 0; L < heights.size() - 1; L++)
        {
            for(int R = heights.size() - 1; R > L; R--)
            {
                int area = (R - L) * min(heights[R], heights[L]);
                maxVal = max(maxVal, area);
            }
        }
        return maxVal;
    }
};
