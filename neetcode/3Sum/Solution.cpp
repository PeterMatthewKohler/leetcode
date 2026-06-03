class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // First sort the array
        std::sort(nums.begin(), nums.end());
        // 3 pointers, shift 1&2 over while iterating 3 across the array
        std::vector<std::vector<int>> res;
        for(int i = 0; i < nums.size()-2; i++) {
            // Skip duplicate i values
            if(i > 0 && nums[i] == nums[i - 1]) {continue;}
            // Two pointer approach, looking for target of -nums[i] = nums[j] + nums[k]
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                if(-nums[i] == nums[j] + nums[k]) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) {j++;} // skip duplicate j values
                }
                else if(-nums[i] > nums[j] + nums[k]) {j++;}
                else {k--;}  // -nums[i] < nums[j] + nums[k]
            }
        }
        return res;
    }
};
