class Solution {
public:
    // Two Pointers
    int maxArea(vector<int>& heights) {
        int L = 0;
        int R = heights.size() -1;
        int maxVal = 0;
        while(L < R)
        {
            int area = (R - L) * min(heights[L], heights[R]);
            maxVal = max(maxVal, area);

            // Shift an index based on whichever height is lower
            if(heights[R] > heights[L])
            {
                L++;
            }
            else
            {
                R--;
            }
        }
        return maxVal;
    }
};
