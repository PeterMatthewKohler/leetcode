class Solution {
public:
    int fib(int n) {
        // Root case
        if(n <= 1)
        {
            return n;
        }
        // Recursive case
        else
        {
            return fib(n - 1) + fib(n - 2);
        }
    }
};
