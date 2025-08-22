class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency of elements
        std::unordered_map<int, int> map;
        for(auto num : nums){map[num]++;}
        // Build a max heap with the frequencies and values as pairs
        std::priority_queue<std::pair<int,int>> heap;
        // Add to our heap
        for(auto pair : map)
        {
            heap.push({pair.second, pair.first});
        }
        // Take top k elements
        std::vector<int> res;
        for(int i = 0; i < k; i++)
        {
            auto val = heap.top();
            heap.pop();
            res.push_back(val.second);
        }
        return res;
    }
};
