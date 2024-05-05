class Solution {
public:
    int numDistinct = 0;
    int climbStairs(int n) {
        // Root case
        if(n == 0)
        {
            return 1;
        }
        else if(n >= 2)
        {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
        else
        {
            return climbStairs(n - 1);
        }
    }
};
