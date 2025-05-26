class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        // Fill prefix with zeros to start
        // Add an extra row and column to avoid edge case checking where we are trying to index
        // out of bounds
        int row = matrix.size();
        int col = row > 0 ? matrix[0].size() : 0;
        prefix = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i = 1; i < row+1; i++)
        {
            for(int j = 1; j < col+1; j++)
            {
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Apply offset (row1/2 + 1 corresponds to row1/2 in original matrix)
        return prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] - prefix[row1][col2 + 1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
