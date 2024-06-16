class Solution {
public:
    int binarySearch(vector<int>& arr, int target)
    {
        // Define our indices
        int L = 0, R = arr.size() - 1, mid;
        // Return value
        int retVal = -1;
        // Perform the search
        while(L <= R)
        {
            mid = (L + R) / 2;
            if(target > arr[mid])
            {
                L = mid + 1;
            }
            else if(target < arr[mid])
            {
                R = mid - 1;
            }
            else
            {
                retVal = mid;
                break;
            }
        }
        return retVal;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool retVal = false;
        for(auto row : matrix)
        {
            if(binarySearch(row, target) != -1)
            {
                retVal = true;
                break;
            }
        }
        return retVal;
    }
};
