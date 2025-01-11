class Solution {
public:
    // Dynamic programming: cache the result at each stage to avoid repeat work
    vector<vector<int>> cache;

    int dp(int r, int c, int rows, int cols)
    {
        // Recursion base case: we go out of bounds
        if(r == rows || c == cols){return 0;}
        // If we've already calculated the value for this coordinate
        if(cache[r][c] != 0){return cache[r][c];}
        // Recursion base case: we hit the goal
        if(r == rows - 1 && c == cols - 1){return 1;}
        // Recursion
        cache[r][c] = dp(r + 1, c, rows, cols) + // Go to the right
            dp(r, c + 1, rows, cols);   // Go down
        return cache[r][c];
    }

    int uniquePaths(int m, int n) {
        // Edge case: if it is a 1x1 grid we have 1 answer
        if(m == 1 && n == 1){return 1;}
        // Initialize our cache
        for(int r = 0; r < m; r++)
        {
            vector<int>row(n, 0);
            cache.push_back(row);
        }
        // Start at top left
        dp(0, 0, m, n);
        return cache[0][0];
    }
};
