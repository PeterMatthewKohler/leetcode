class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> retVect(n + 1, 0);
        for(int i = 1; i <= n; i++)
        {
            retVect[i] = retVect[i >> 1] + (i & 1); 
        }
        return retVect;
    }
};
