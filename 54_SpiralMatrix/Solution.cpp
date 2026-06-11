class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse right
            for (int col = left; col <= right; col++) {
                res.push_back(matrix[top][col]);
            }
            top++;

            // Traverse down
            for (int row = top; row <= bottom; row++) {
                res.push_back(matrix[row][right]);
            }
            right--;
            // First two (right and down) always happen while the loop condition is valid
            // Going left and up we need to check first if we haven't already added those numbers
            // Traverse left
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    res.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // Traverse up
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    res.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return res;
    }
};
