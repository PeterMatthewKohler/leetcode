class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1)
        {
            // Sort by ascending weight
            sort(stones.begin(), stones.end());
            int remain = abs(stones.back() - stones[stones.size() - 2]);
            stones.pop_back();
            stones.pop_back();
            if(remain != 0)
            {
                stones.push_back(remain);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};
