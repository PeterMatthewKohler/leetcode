class Solution {
public:
    int recursion(uint32_t n)
    {
        // Recursion base case
        if(n == 0){return 0;}
        // Perform the recursion
        return (n & 1) + recursion(n >> 1);
    }

    int hammingWeight(uint32_t n) {
        return recursion(n);
    }
};
