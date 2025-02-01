class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create map with frequency of all elements
        std::unordered_map<int,int> map;
        for(auto num : nums)
        {
            if(map.find(num) != map.end())
            {
                map[num]++;
            }
            else
            {
                map.insert({num, 1});
            }
        }
        // For each element, add frequency to a list of buckets
        vector<vector<int>> frequency(nums.size() + 1);
        for(auto itr : map)
        {
            frequency[itr.second].push_back(itr.first);
        }
        // Pick top k numbers from buckets, starting from n down to 1
        vector<int> retVect; // Return object
        for(int idx = frequency.size() - 1; idx > 0; --idx)
        {
            for(int n : frequency[idx])
            {
                retVect.push_back(n);
                if(retVect.size() == k){return retVect;}
            }
        }
        return retVect;
    }
};
