class Solution {
public:
    // Traverse grid using BFS
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        // Use a 2D array to track where we've been
        vector<vector<int>> visited(ROWS, vector<int>(COLS)); // Initialize to all 0
        queue<pair<int,int>> queue; // queue to store each level
        // Start at top left and traverse through entire matrix
        // Edge case
        if(grid[0][0] == 1 || // top left is blocked and we can't even start
           grid[ROWS-1][COLS-1] == 1) // bottom right is blocked and we can never finish
           {
            return -1;
           }
        // Otherwise perform BFS starting at topleft
        queue.push(pair<int,int>(0,0));
        visited[0][0] = 1;  // Mark as visited
        int length = 1;
        while(queue.size() > 0)
        {
            int queueLength = queue.size(); // How many items we need to iterate through for this level
            for(int i = 0; i < queueLength; i++)
            {
                pair<int,int> currPair = queue.front();
                queue.pop();
                int r = currPair.first;
                int c = currPair.second;
                // If we have succeeded return the length of the path
                if(r == ROWS-1 && c == COLS-1)
                {
                    return length;
                }

                // Build the next level (the neighboring nodes)
                int neighbors[8][2] = {
                    {r - 1, c -1},  // top left
                    {r - 1, c},     // above
                    {r - 1, c + 1}, // top right
                    {r, c - 1},     // left
                    {r, c + 1},     // right
                    {r + 1, c -1},  // bottom left
                    {r + 1, c},     // below
                    {r + 1, c + 1}  // bottom right
                };
                // Iterate through the neighbors
                for(int j = 0; j < 8; j++)
                {
                    int newR = neighbors[j][0];
                    int newC = neighbors[j][1];
                    // Base cases
                    if(min(newR, newC) < 0 ||           // Out of bounds
                       newR == ROWS || newC == COLS ||
                       visited[newR][newC] == 1 ||        // already been here
                       grid[newR][newC] == 1)           // blocked
                       {
                        continue;   // Invalid, continue with next iteration
                       }
                    // If we have a valid neighbor coordinate, add it to the queue
                    queue.push(pair<int,int>(newR, newC));
                    visited[newR][newC] = 1;  // Mark we have visited there
                }
            }   // End of loop generating next 'level' to be traversed
            length++;   // Increment our pathlength
        }
        // If we've reached this point there is no clear path, return -1
        return -1;
    }
};
