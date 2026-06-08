class Solution {
public:
    void preOrder(std::vector<std::vector<char>>& grid, int row, int col) {
        // Base case: we've already been here or it's not land
        if(grid[row][col] != '1'){return;}
        // Flip this section to 0
        grid[row][col] = '0';
        // Traverse to the other sections
        if(row-1 >= 0){preOrder(grid, row-1, col);}  // North
        if(row+1 < grid.size()){preOrder(grid, row+1, col);} // South
        if(col+1 < grid[0].size()){preOrder(grid, row, col+1);}  // East
        if(col-1 >= 0){preOrder(grid, row, col-1);}  // West
    }

    int numIslands(vector<vector<char>>& grid) {
        // Traverse the grid, incrementing count when we encounter an island.
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1'){res++;}
                preOrder(grid, i, j);
            }
        }
        return res;
    }
};
