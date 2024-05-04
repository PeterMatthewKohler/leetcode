class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_set<int> set;
        int numUnique = 0;
        int sortedIndex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = set.find(nums[i]);
            if(itr == set.end())
            {
                set.insert(nums[i]);
                numUnique++;
                nums[sortedIndex] = nums[i];
                sortedIndex++;
            }
        }
        return numUnique;
    }
};
