class Solution {
public:
    // Cache our results to avoid repeat work
    vector<vector<int>> cache;
    // Traverse through the grid using recursion
    int traverse(int r, int c, int rows, int cols, vector<vector<int>>& obstacleGrid)
    {
        // Recursion base case: we go out of bounds
        if(r == rows || c == cols){return 0;}   // This is not a valid path
        // If we have already calculated the result from this coordinate
        if(cache[r][c] != 0){return cache[r][c];}
        // If we hit the target
        if(r == rows - 1 && c == cols - 1){return 1;}

        // Do the recursion
        // 4 Cases:
        int right = 0;
        int down = 0;
        if(r + 1 == rows || obstacleGrid[r + 1][c] == 1)   // We're on the bottom edge, consider that a boundary
        {
            down = 1;
        }
        if(c + 1 == cols || obstacleGrid[r][c + 1] == 1)    // We're on the right edge, consider that a boundary
        {
            right = 1;
        }
        // 1. We have no obstacle below or to the right of us
        if(!right && !down)
        {
            cache[r][c] = traverse(r + 1, c, rows, cols, obstacleGrid) + // Traverse down
                traverse(r, c + 1, rows, cols, obstacleGrid); // Traverse to the right
        }
        // 2. We have an obstacle to the right ONLY
        else if(right && !down)
        {
            cache[r][c] = traverse(r + 1, c, rows, cols, obstacleGrid);   // Traverse down
        }
        // 3. We have an obstacle down ONLY
        else if(!right && down)
        {
            cache[r][c] = traverse(r, c + 1, rows, cols, obstacleGrid);   // Traverse to the right
        }
        // 4. We are totally blocked, there is no viable path from this coordinate
        else
        {
            cache[r][c] = 0;
        }
        return cache[r][c];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Edge case: we have a 1x1 grid
        // If the 1x1 grid is blocked(1), we have no paths
        // If it is open(0), we have 1 path
        if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1){return !obstacleGrid[0][0];}
        // Edge case: our first coordinate is blocked
        if(obstacleGrid[0][0]){return 0;}
        // Init our cache
        for(int r = 0; r < obstacleGrid.size(); r++)
        {
            vector<int> row(obstacleGrid[0].size(), 0);
            cache.push_back(row);
        }
        // Traverse the grid
        traverse(0, 0, obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid);
        return cache[0][0]; // Return the results
    }
};
