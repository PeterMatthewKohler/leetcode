class Solution {
public:
    int calcArea(int leftHeight, int rightHeight, int span)
    {
        return min(leftHeight,rightHeight)*(span);
    }
    // Two pointer problem
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while(l < r)
        {
            res = max(calcArea(height[l], height[r], r-l), res);
            // Which pointer do we shift?
            // Try just choosing the smaller one
            if(height[l] > height[r]){r--;}
            else{l++;}
        }
        return res;
    }
};
