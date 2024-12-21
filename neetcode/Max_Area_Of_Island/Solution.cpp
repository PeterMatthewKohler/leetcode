class Solution {
public:
    int maxArea = 0;
    int ROWS = 0;   // rows in grid
    int COLS = 0;   // cols in grid
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        // Recursion base cases
        if(min(r, c) < 0 ||         // Outside of the grid
           r == ROWS || c == COLS ||
           grid[r][c] == 0)    // We are no longer on land
        {
            return 0;
        }
        // Mark this part of the island as visited and remove from graph
        grid[r][c] = 0;
        // Increment the area by one
        int area = 1;
        // Recursively traverse the grid
        area += dfs(grid, r+1, c);
        area += dfs(grid, r-1, c);
        area += dfs(grid, r, c+1);
        area += dfs(grid, r, c-1);
        // We've traversed the island return the total area of it
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Traverse the entire grid, comparing the maxArea to the area of each island found
        ROWS = grid.size();
        COLS = grid[0].size();
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == 1) // We've found an island, traverse it and find it's area
                {
                    int area = dfs(grid, r, c);
                    // Update our maximum area
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
