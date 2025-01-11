class Solution {
public:
    // Brute force solution
    int bruteForce(int r, int c, int rows, int cols)
    {
        // Recursion base case: we go out of bounds
        if(r == rows || c == cols){return 0;}
        // Recursion base case: we make it to the goal
        if(r == rows - 1 || c == cols - 1){return 1;}
        // Recursion
        return bruteForce(r + 1, c, rows, cols) + // Go to the right
            bruteForce(r, c + 1, rows, cols); // Go down
    }
    int uniquePaths(int m, int n) {
        return bruteForce(0, 0, m, n);
    }
};
