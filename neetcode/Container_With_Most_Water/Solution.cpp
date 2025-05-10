class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Edge case: heights.size() == 2
        if(heights.size() == 2){return min(heights[0], heights[1]);}
        int retArea = 0;
        int L = 0;  // Start from the left and go right
        int R = heights.size() - 1; // Start from the right and go left
        while(R > L)
        {
            // Shift pointers based on whichever height is smaller
            int area = (R - L) * min(heights[L], heights[R]);
            retArea = max(retArea, area);
            if(heights[R] > heights[L]){L++;}
            else{R--;}
        }
        return retArea;
    }
};

