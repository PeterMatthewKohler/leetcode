class Solution {
public:
    // Sliding window
    int maxProfit(vector<int>& prices) {
        int maxVal = 0;
        int lowestPrice = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            lowestPrice = min(lowestPrice, prices[i]);
            maxVal = max(maxVal, prices[i] - lowestPrice); 
        }
        return maxVal;
    }
};
