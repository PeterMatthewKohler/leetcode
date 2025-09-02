class Solution {
public:
    // Want subarray nums [i,j] % k == 0
    // Write: (P(j+1) - P(i)) % k == 0
    // Rewrite: P(j+1) % k == P(i) % k
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        std::unordered_map<int,int> map;
        map[0] = 1;
        // Looking for subarrays P[i] % k = P(j+1) % k 
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sum = (int)((sum % k + k) % k);  // normalize to [0..k-1]
            if(map.count(sum % k)){count += map[sum % k];}
            map[sum % k]++;
        }
        return count;
    }
};
