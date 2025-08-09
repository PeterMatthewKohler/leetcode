class Solution {
public:
    // Trivial solution: use a set
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for(int num : nums)
        {
            if (set.count(num) == 0){set.insert(num);}
            else{return num;}
        }
    }
};

