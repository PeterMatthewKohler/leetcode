class Solution {
public:
    // We want subarray sums nums[i..j] == k.
    // With prefix sums P, nums[i..j] = P[j+1] - P[i].
    // Let S be the running sum up to j (i.e., P[j+1]).
    // Then P[i] must equal S - k.
    // Maintain a hash map count[x] = # of prior prefixes equal to x.
    // At each j: ans += count[S - k]; then ++count[S].
    // Initialize count[0] = 1 to allow subarrays starting at index 0.
    // Use 64-bit for S; query before incrementing to avoid counting empty subarrays.
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        std::unordered_map<int,int> map; // Track occurences of a prefix sum
        map[0] = 1; // Initialize to find first sum @ (sum - k)
        // Run a prefix sum, incrementing the number of occurances
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            // We want total number of occurances of prefix value (sum - k)
            if(map.count(sum - k)){count += map[sum - k];}
            map[sum]++; // Increment sum occurance
        }
        return count;
    }
};
