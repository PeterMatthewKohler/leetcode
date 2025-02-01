class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retArr; // What we are returning
        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    retArr.push_back(i);
                    retArr.push_back(j);
                    return retArr;
                }
            }
        }
    }
};
