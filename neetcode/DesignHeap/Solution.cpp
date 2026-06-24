class MinHeap {
public:
    // Use 1 based indexing for vector
    // For Node i:
    // Parent = i/2
    // Left child = 2*i
    // Right child = 2*i + 1

    std::vector<int> heap_;

    MinHeap() {heap_.resize(1, 0);}

    // While this node has a left child:
    // - choose the smaller child
    // - if(parent > child){swap}
    // - else{stop}
    void percolate(int idx) {
        while(2*idx < heap_.size()) {
            // Choose the smaller child
            int childIdx = (heap_[2*idx+1] < heap_[2*idx]) ? 2*idx+1 : 2*idx;
            if(heap_[idx] > heap_[childIdx]) {
                // Swap
                int tmp = heap_[idx];
                heap_[idx] = heap_[childIdx];
                heap_[childIdx] = tmp;
                idx = childIdx;
            }
            // Otherwise, stop
            else{break;}
        }
    }

    // Push at the bottom and bubble up
    void push(int val) {
        heap_.push_back(val);
        int idx = heap_.size() - 1;
        // Bubble up
        while(idx > 1 && heap_[idx] < heap_[idx/2]) {
            // Swap
            int tmp = heap_[idx];
            heap_[idx] = heap_[idx/2];
            heap_[idx/2] = tmp;
            idx /= 2;
        }
    }

    // Pull from top, then take node at bottom, move to top
    // then percolate down
    int pop() {
        if(heap_.size() <= 1){return -1;}
        else if(heap_.size() == 2) {
            int res = heap_[1];
            heap_.pop_back();
            return res;
        }
        else {
            int res = heap_[1];
            heap_[1] = heap_[heap_.size()-1];
            heap_.pop_back();
            percolate(1);
            return res;
        }
    }

    // Return value at top of heap
    int top() {
        if(heap_.size() <= 1){return -1;}
        else{return heap_[1];}
    }

    // Build heap from array
    // For each parent, percolate down (indices: n/2 to 1)
    void heapify(const vector<int>& arr) {
        heap_.clear();
        heap_.push_back(0);
        // Insert elements
        for(const auto& x : arr){heap_.push_back(x);}
        // For each parent in the heap, percolate down
        for(int idx = heap_.size() / 2; idx >= 1; idx--) {percolate(idx);}
    }
};
