class DynamicArray {
public:
    int* arr_ = nullptr;
    int capacity_;  // Total allocated size
    int length_;    // number of elements currently stored

    DynamicArray(int capacity) {
        arr_ = new int[capacity];
        capacity_ = capacity;
        length_ = 0;
    }

    int get(int i) {
        return arr_[i];
    }

    void set(int i, int n) {
        arr_[i] = n;
        return;
    }

    void pushback(int n) {
        if(length_ == capacity_){resize();}
        arr_[length_] = n;
        length_++;
    }

    int popback() {
        return arr_[(length_--) - 1];
    }

    void resize() {
        int* tmp = arr_;
        arr_ = new int[capacity_*2];
        for(int idx = 0; idx < capacity_; idx++){arr_[idx] = tmp[idx];}
        capacity_ *= 2;
        return;
    }

    int getSize() {
        return length_;
    }

    int getCapacity() {
        return capacity_;
    }
};
