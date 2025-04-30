class Solution {
public:
    int average(vector<int>& arr)
    {
        int sum = 0;
        for(auto num : arr)
        {
            sum += num;
        }
        return sum / arr.size();
    }
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // Edge case: threshold is 0, return max number of windows possible
        if(threshold == 0){return arr.size() - k + 1;}
        
        int retVal = 0;
        std::vector<int> subArr;
        // Make our first subarray
        for(int R = 0; R < arr.size(); R++)
        {
            subArr.push_back(arr[R]);
            if(R >= k - 1)
            {
                if(average(subArr) >= threshold){retVal++;}
                // Remove oldest value
                subArr.erase(subArr.begin());
            }
        }
        return retVal;
    }
};
