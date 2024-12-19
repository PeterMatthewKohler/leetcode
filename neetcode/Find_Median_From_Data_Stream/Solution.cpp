class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxHeap;    // Left half of array
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Right half of array
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);  // Just default to pushing to one side and then sort

        // If the right half is not empty, and our left middle value(after sorting)
        // is bigger than our right middle value (after sorting) we swap it over
        if(!minHeap.empty() && (maxHeap.top() > minHeap.top()))
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // If our left half of the array is too big
        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // If our right half of the array is too big
        if(minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) // Even numbers on both sides, calc the median
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if(maxHeap.size() > minHeap.size())    // Middle is on the left half of array
        {
            return maxHeap.top();
        }
        else    // Middle is on the right half of the array
        {
            return minHeap.top();
        }
    }
};
