class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Use BFS to recurse through the grid, incrementing our turn count for each layer we go
        std::queue<std::pair<int,int>> q;
        // Each layer is the coordinates of rotten oranges
        // Seed our BFS with first round of rotten oranges
        int count = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == 2) {
                    q.push({row, col});
                }
            }
        }
        if(!q.empty()){
            // Now start rotting all connected oranges
            auto validIdx = [&grid](int row, int col) {
                return (row >= 0 && row < grid.size() &&
                        col >= 0 && col < grid[0].size());
            };
            while(!q.empty()) {
                int len = q.size();
                bool rotted = false;
                for(int i = 0; i < len; i++) {
                    auto p = q.front();
                    q.pop();
                    // North
                    if(validIdx(p.first-1, p.second) && grid[p.first-1][p.second] == 1){
                        grid[p.first-1][p.second] = 2;
                        q.push({p.first-1, p.second});
                        rotted = true;
                    }
                    // East
                    if(validIdx(p.first, p.second+1) && grid[p.first][p.second+1] == 1){
                        grid[p.first][p.second+1] = 2;
                        q.push({p.first, p.second+1});   
                        rotted = true; 
                    }
                    // South
                    if(validIdx(p.first+1, p.second) && grid[p.first+1][p.second] == 1){
                        grid[p.first+1][p.second] = 2;
                        q.push({p.first+1, p.second});
                        rotted = true;
                    }
                    // West
                    if(validIdx(p.first, p.second-1) && grid[p.first][p.second-1] == 1){
                        grid[p.first][p.second-1] = 2;
                        q.push({p.first, p.second-1});
                        rotted = true;    
                    }
                }
                if(rotted){count++;}
            }
        }
        // Check for any remaining fresh oranges
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == 1) {return -1;}
            }
        }
        return count;
    }
};
