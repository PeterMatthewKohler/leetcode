class Solution {
public:
    void merge(vector<int>& arr, int left, int m, int right)
    {
        // Copy sorted left and right arrays into temp arrays
        vector<int> L = {arr.begin() + left, arr.begin() + m + 1};
        vector<int> R = {arr.begin() + m + 1, arr.begin() + right + 1};

        int i = 0; // index for L
        int j = 0; // index for R
        int k = left; // index for arr

        while(i < L.size() && j < R.size())
        {
            if(L[i] <= R[j]){arr[k] = L[i++];}
            else{arr[k] = R[j++];}
            k++;
        }
        // One of the halves will have elements remaining
        while(i < L.size()){arr[k++] = L[i++];}
        while(j < R.size()){arr[k++] = R[j++];}
    }

    vector<int> mergeSort(vector<int>& arr, int l, int r)
    {
        // Base case of recursion, just return the single value array
        if(l == r) {return arr;}
        // Middle index of the array
        int m = (l + r) / 2;
        // Sort left half
        mergeSort(arr, l, m);
        // Sort right half
        mergeSort(arr, m + 1, r);
        // Merge sorted halves after recursion is done
        merge(arr, l, m, r);

        return arr;
    }

    vector<int> sortArray(vector<int>& nums) {
        // Use merge sort
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
