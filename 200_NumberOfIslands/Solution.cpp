class Solution {
public:
    // Use DFS to traverse the entire island when we find one
    void dfs(vector<vector<char>>&grid, int row, int col)
    {
        // Recursion base case: we've left the grid or left the island
        if((row < 0) || (col < 0) || row >= grid.size() || col >= grid[0].size()
           || (grid[row][col] == '0')){return;}
        // Mark the section of the island as a '0'
        grid[row][col] = '0';
        // Traverse to the north, south, east, and west
        dfs(grid, row-1, col); // North
        dfs(grid, row+1, col); // South
        dfs(grid, row, col+1); // East
        dfs(grid, row, col-1); // West
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        // Traverse the entire grid, running dfs when we find an island
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
