class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Use binary search to determine eating speed
        // Min is 1, max is maximum element in array
        int L = 1;
        // Right index is the maximum element in the array
        std::vector<int>::iterator itr;
        itr = std::max_element(piles.begin(), piles.end());
        int R = *itr;
        int retVal = R;
        while(L <= R)
        {
            int mid = (L + R) / 2;
            std::int64_t totalTime = 0;
            for(int pile : piles)
            {
                // If after division, there is a remainder, we round up to the next integer.
                totalTime += std::ceil(static_cast<double>(pile) / mid);
            }
            // If totalTime is less than or equal to allowed time h, we can eat slower, and so we shift left
            if(totalTime <= h)
            {
                retVal = mid;
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        return retVal;
    }
};
