class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Just make a second vector
        std::vector<int> res;
        for(const auto& num : nums) {
            if(num != 0){res.push_back(num);}
        }
        while(res.size() < nums.size()){res.push_back(0);}
        for(int idx = 0; idx < nums.size(); idx++){nums[idx] = res[idx];}
    }
};
