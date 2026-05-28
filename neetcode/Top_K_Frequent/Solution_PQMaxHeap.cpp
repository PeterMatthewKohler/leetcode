class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Using priority queue with custom comparator to count frequency for us
        using Pair = std::pair<int, int>;   // <number, frequency>
        // Define custom comparator for max heap
        auto cmp = [](const Pair& a, const Pair& b) {
            return a.second < b.second; // If a.freq < b.freq a has lower priority than b
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> maxHeap;
        // Build out frequency map
        std::unordered_map<int, int> fMap;  // <num, freq>
        for(const auto& num : nums){fMap[num]++;}
        // Add all Pairs to maxHeap
        for(const auto& [num, freq] : fMap) {
            Pair p = {num, freq};
            maxHeap.push(p);
        }
        // Grab top k values and add to vector
        std::vector<int> res;
        for(; k > 0; k--) {
            res.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return res;
    }
};

