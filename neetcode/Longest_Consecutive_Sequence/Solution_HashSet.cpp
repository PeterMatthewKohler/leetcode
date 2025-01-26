class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set;
        int maxSeq = 0;
        // Create an unordered set w/ all numbers in nums
        for(auto num : nums)
        {
            set.insert(num);
        }
        // Get all sequence starting points(starting point doesn't have a number smaller than it to it's left)
        for(const auto &num : set)
        {
            int sequence = 1;
            if(set.find(num - 1) == set.end()) // if we have a sequence starting point
            {
                // Loop until we no longer have a next item in sequence
                int seqNum = num;
                while(set.find(seqNum + 1) != set.end())
                {
                    seqNum++;
                    sequence++;
                }
            }
            // Update max sequence value
            maxSeq = maxSeq > sequence ? maxSeq : sequence;
        }
        return maxSeq;
    }
};
