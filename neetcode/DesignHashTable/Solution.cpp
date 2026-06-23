class HashTable {
public:

    int size_;
    int capacity_;

    // Vectors to store the keys and values
    std::vector<std::vector<std::pair<int,int>>> table_;

    HashTable(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        table_.resize(capacity);
    }

    int hashFunc(int key) {
        return key % capacity_;
    }

    double calcLF() {
        return static_cast<double>(size_) / static_cast<double>(capacity_);
    }

    void insert(int key, int value) {
        // Compute our hash (Do we need to be able to handle negative value keys?)
        int hash = hashFunc(key);
        // Get our bucket
        auto& bucket = table_[hash];
        // Check for collisions, if exists, overwrite
        for(auto it = bucket.begin(); it < bucket.end(); it++) {
            // If we find it
            if(it->first == key){it->second = value; return;}
            // If we're already past where it should be
            if(it->first > key){
                bucket.insert(it, {key, value});
                size_++;
                resize();
                return;}
        }
        // We get to the end and haven't inserted it yet, add it to the end
        bucket.push_back({key, value});
        size_++;
        resize();
        return;
    }

    int get(int key) {
        // Compute our hash
        int hash = hashFunc(key);
        // Get our bucket
        auto& bucket = table_[hash];
        // Look for our key
        for(auto it = bucket.begin(); it < bucket.end(); it++) {
            // If we find it
            if(it->first == key){return it->second;}
        }
        return -1;
    }

    bool remove(int key) {
        // Calc our hash
        int hash = hashFunc(key);
        auto& bucket = table_[hash];
        // Look for the key
        for(auto it = bucket.begin(); it < bucket.end(); it++) {
            if(it->first == key){bucket.erase(it);
            size_--;
            return true;}
        }
        return false;
    }

    int getSize() const {
        return size_;
    }

    int getCapacity() const {
        return capacity_;
    }

    void resize() {
        // Calc and update load factor
        double lf = static_cast<double>(size_) / static_cast<double>(capacity_);
        if(lf >= 0.5) {
            // Doubles the capacity of the hash table if load factor reaches 0.5 or higher
            capacity_ *= 2;
            table_.resize(capacity_);
        }
    }
};

