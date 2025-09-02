class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // Sliding window with a frequency map
        int L = 0;
        std::unordered_map<int, int> map;
        long long res = 0;
        long long window = 0;
        for(int R = 0; R < nums.size(); R++)
        {
            // Add our number to the frequency count
            map[nums[R]]++;
            window += nums[R];
            // If we add a duplicate, shrink from the left until gone
            while(map[nums[R]] > 1)
            {
                map[nums[L]]--;
                window -= nums[L];
                L++;
            }
            // If our window is bigger than k, shift left pointer
            if(R - L + 1 > k){L++;}
            // If our window is the right size, calculate the sum
            if(R - L + 1 == k)
            {
                res = max(res, window);
                // Slide window over
                map[nums[L]]--;
                window -= nums[L];
                L++;
            }
        }
        return res;
    }
};
