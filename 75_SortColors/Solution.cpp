class Solution {
public:
    void sortColors(vector<int>& nums) {
       // Use bucket sort
       // Array contains only 0, 1, 2
       int counts[] = {0,0,0};
       // Iterate through the array to determine the counts
       for(int n : nums)
       {
            counts[n]++;
       }
       int i = 0;
       for(int n = 0; n < 3; n++)
       {
            for(int j = 0; j < counts[n]; j++)
            {
                nums[i] = n;
                i++;
            }
       }
    }
};
