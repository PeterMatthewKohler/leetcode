class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Use a max-heap
        priority_queue<pair<double, pair<int,int>>> maxHeap;
        for(auto pt : points)
        {
            double distance = sqrt(pow(pt[0], 2) + pow(pt[1], 2));
            maxHeap.push({distance, {pt[0], pt[1]}});
            // Only keep the smallest k elements
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        // Construct the return vector
        vector<vector<int>> retVect;
        while(!maxHeap.empty())
        {
            retVect.push_back({maxHeap.top().second.first,
                               maxHeap.top().second.second});
            maxHeap.pop();
        }
        return retVect;
    }
};
