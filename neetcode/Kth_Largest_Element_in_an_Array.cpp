class Solution {
public:
    vector<int> quickSort(vector<int>& arr, int s, int e)
    {
        // Base case
        if(e - s + 1 <= 1) {return arr;}
        // Set our pointers
        int pivot = arr[e];
        int left = s;
        // Partition: elements smaller than pivot moved to the left side
        for(int i = s; i < e; i++)
        {
            if(arr[i] < pivot)
            {
                int tmp = arr[left];
                arr[left] = arr[i];
                arr[i] = tmp;
                left++;
            }
        }
        // Move pivot in-between left and right sides
        arr[e] = arr[left];
        arr[left] = pivot;
        // Sort the next partitions
        quickSort(arr, s, left - 1);    // Left side
        quickSort(arr, left + 1, e);    // Right side

        return arr;
    }
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the array
        quickSort(nums, 0, nums.size() - 1);
        // Get the sorted kth value
        return nums[nums.size()-k];
    }
};
