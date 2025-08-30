class Solution {
public:
    long long calcHours(std::vector<int>& piles, int rate)
    {
        long long sum = 0;
        // Calc the total hours required to eat all piles
        for(auto pile : piles)
        {
            sum += (pile % rate == 0) ? (pile / rate) : (pile / rate) + 1;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary Search
        int minRate = 1;
        int maxRate = *(std::max_element(piles.begin(), piles.end())); // Max element of the guaranteed non-empty array
        // Binary search
        while(minRate < maxRate)
        {
            int midRate = (maxRate + minRate) / 2;
            long long hours = calcHours(piles, midRate);
            if(hours > h){minRate = midRate + 1;} // Too slow, check right side
            else{maxRate = midRate;} // Solution is either mid or less than mid
        }
        return minRate;
    }
};
