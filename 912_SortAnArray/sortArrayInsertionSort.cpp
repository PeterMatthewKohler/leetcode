class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Use insertion sort
        for(int i = 1; i < nums.size(); i++)
        {
            int j = i - 1;
            while(j >= 0 && nums[j+1] < nums[j])
            {
                int tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
                j--;
            }
        }
        return nums;
    }
};
