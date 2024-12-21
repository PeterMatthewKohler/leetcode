class Solution {
public:
    int islandCount = 0;
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        // Get size of grid
        int ROWS = grid.size();
        int COLS = grid[0].size();
        // Recursion base cases
        if(min(r,c) < 0 ||  // Out of bounds
           r == ROWS || c == COLS ||
           grid[r][c] == '0')  // No longer on land
        {
            return;
        }
        // Mark this node as visited and remove it from the graph
        grid[r][c] = '0';
        // Recursively visit all parts of the island
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Iterate through every part of the grid and perform dfs if it is land
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == '1')   // We've found land, start exploring with DFS
                {
                    islandCount++;
                    dfs(grid, r, c);
                }
            }
        }
        return islandCount;
    }
};
