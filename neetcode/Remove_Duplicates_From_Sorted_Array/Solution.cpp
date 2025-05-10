class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_set<int> set;
        int k = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i] << std::endl;
            if(set.count(nums[i]) == 0) // First occurance, keep
            {
                set.insert(nums[i]);
                k++;
            }
            else // Multiple, remove
            {
                nums.erase(nums.begin() + i);
                i--; // Lose an element, need to go back one in index
            }
        }
        return k;
    }
};
