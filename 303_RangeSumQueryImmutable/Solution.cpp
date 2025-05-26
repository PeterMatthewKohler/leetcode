class NumArray {
public:
    std::vector<int> prefix;
    NumArray(vector<int>& nums) {
        int total = 0;
        for(int num : nums)
        {
            total += num;
            prefix.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        int prefixLeft = left > 0 ? prefix[left - 1] : 0;
        return prefix[right] - prefixLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
