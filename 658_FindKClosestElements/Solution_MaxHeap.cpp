class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Maxheap to track the k closest elements so far
        std::priority_queue<std::pair<int,int>> maxHeap;
        // If the top of the heap is larger than the new element,
        // replace the top with the new element
        for(auto num : arr)
        {
            int distance = abs(x - num);
            if(maxHeap.size() < k){maxHeap.push({distance, num});}
            else
            {
                if(maxHeap.top().first > distance)
                {
                    maxHeap.pop();
                    maxHeap.push({distance, num});
                }
            }
        }
        // Take k closest elements
        std::vector<int> res;
        while(!maxHeap.empty())
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        // Sort in ascending order
        std::sort(res.begin(), res.end());
        return res;
    }
};
