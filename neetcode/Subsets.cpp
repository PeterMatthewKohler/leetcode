class Solution {
    vector<vector<int>> retVect = {{}};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Solution is to do DFS with backtracking and for each attempt we generate a vector from it
        // add add it to the list
        vector<vector<int>> retVect;
        vector<int> subset;
        depthFirstSearch(nums, 0, subset, retVect);
        return retVect;
    }

private:
    void depthFirstSearch(vector<int>& nums, int i, vector<int> subset, vector<vector<int>>& retVect)
    {
        // Recursion base case(we have hit the end of a backtrack attempt)
        if(i >= nums.size())
        {
            retVect.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);  // Add to our backtrack attempt
        depthFirstSearch(nums, i+1, subset, retVect);
        subset.pop_back();
        depthFirstSearch(nums, i+1, subset, retVect);
    }
};
