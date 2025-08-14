class Solution {
public:
    // Optimized
    vector<int> twoSum(vector<int>& nums, int target) {
        // Edge case: if vector has 2 numbers
        if(nums.size() == 2){return {0,1};}
        std::unordered_map<int, int> map;   // complement, index
        for(int i = 0; i < nums.size(); i++)    // Build a table of the complement and it's index in the array
        {
            map[nums[i]] = i;
        }
        // Now iterate through the array, looking for the complement, if it exists
        int idx1, idx2;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.count(target - nums[i]) != 0)
            {
                // Protect against returning the same number twice
                if(i != map[target - nums[i]])
                {
                    idx1 = i;
                    idx2 = map[target - nums[i]];
                }
            }
        }
        return {idx1, idx2};
    }
};
