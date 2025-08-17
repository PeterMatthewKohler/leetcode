class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Use quickselect algorithm
        std::vector<int> arr = nums; // Work off a copy
        std::srand(std::time(nullptr)); // Seed our random selection once
        // Create our partition bins
        std::vector<int> larger;
        std::vector<int> smaller;
        int equal = 0;
        // Run the algorithm
        while(true)
        {
            int pivot = arr[std::rand() % arr.size()];
            // Parition the elements
            for(auto num : arr)
            {
                if(num == pivot){equal++;} // Equal to the pivot
                else if(num > pivot){larger.push_back(num);} // Larger than the pivot
                else{smaller.push_back(num);}
            }
            // Where do we search next?
            if(k <= larger.size()){arr = larger;} // kth largest is in larger, search there
            else if(k > larger.size() + equal) // kth largest is in smaller
            {
                arr = smaller;
                k = k - (larger.size() + equal); // We are discarding larger.size() + equal number of elements, need to update
                                               // our rank we are searching for
            }
            else{return pivot;} // Pivot is the kth largest
            // Reset partitions
            larger.clear();
            smaller.clear();
            equal = 0;
        }
    }
};
