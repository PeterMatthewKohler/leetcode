class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 1){return 1;}
        // Sort the meetings by their start time
        std::sort(intervals.begin(), intervals.end());
        // Use a min heap to store the end times and compare the start times with the foremost upcoming end time to see if the room will be free
        // Don't remember default constructor, use a comparator
        auto cmp = [](int a, int b){return a > b;};
        std::priority_queue<int, std::vector<int>, decltype(cmp)> minHeap;
        for(const auto& mtg : intervals) {
            if(minHeap.empty()){minHeap.push(mtg[1]);}
            else {
                // Compare the start time of the new meeting with the end time of the foremost upcoming end time
                if(mtg[0] < minHeap.top()){minHeap.push(mtg[1]);}   // We need another room
                else {minHeap.pop(); minHeap.push(mtg[1]);}   // Meeting room has freed up
            }
        }
        return minHeap.size();
    }
};
