class Solution {
public:
    int maxRotTime = 0;
    int ROWS = 0;
    int COLS = 0;

    int bfs(vector<vector<int>>& grid,  // Input grid
            vector<pair<int,int>> rottenFruit)   // coordinates of rotten fruit
    {
        int time = 0;   // Time to turn all connected fruit rotten, start at 0
        queue<pair<int,int>> queue; // Queue to track each level
        for(auto coord : rottenFruit)
        {
            queue.push(coord);
        }
        while(queue.size() > 0)
        {
            int queueLength = queue.size();
            // Iterate through the level
            for(int i = 0; i < queueLength; i++)
            {
                auto currPt = queue.front();
                queue.pop();
                int newR = currPt.first;
                int newC = currPt.second;

                // Build the next level w/ neighbors
                vector<pair<int,int>> neighbors = {
                    {newR - 1, newC},     // North
                    {newR + 1, newC},     // South
                    {newR, newC - 1},     // West
                    {newR, newC + 1}      // East
                };
                // If the neighbors have fresh fruit, add to the next level and turn them rotten in the grid
                for(auto neighbor : neighbors)
                {
                    int R2 = neighbor.first;
                    int C2 = neighbor.second;
                    // Recursion base cases
                    if(min(R2, C2) < 0 || // Outside of grid
                       R2 == ROWS || C2 == COLS ||
                       grid[R2][C2] != 1)   // Not a fresh piece of fruit
                    {
                        continue;
                    }
                    // Fresh piece of fruit, add to next level and turn rotten
                    grid[R2][C2] = 2;
                    queue.push({R2, C2});
                }
            }
            // If we have a next level increment time required by one
            if(queue.size() > 0){time++;}
        }
        // We've traversed all the connected fruit and turned them rotten, return time requred for traversal
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Find all rotten fruit in grid and run BFS using them to generate neighbors
        ROWS = grid.size();
        COLS = grid[0].size();
        vector<pair<int,int>> rottenFruit;
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(grid[i][j] == 2) // If we find a piece of rotten fruit
                {
                    rottenFruit.push_back({i,j});
                }
            }
        }
        if(rottenFruit.size() > 0)
        {
            maxRotTime = max(maxRotTime, bfs(grid, rottenFruit));  // Update our maximum rot time required
        }
        // We've gone through the whole array, check if there are any remaining fresh fruit
        // If so, return -1
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(grid[i][j] == 1){return -1;} // State is impossible with this grid
            }
        }
        // State is possible and will take 'maxRotTime' time to achieve
        return maxRotTime;
    }
};
