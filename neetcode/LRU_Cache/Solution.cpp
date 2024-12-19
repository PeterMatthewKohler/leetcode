class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> map; // Hash map to store key, value pairs, keep a pointer to the position in ordering list with it
    list<int> order;    // Order of use of elements in LRU cache class
    int capacity;   // Capacity of structure
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // If element doesn't exist, return -1
        if(map.find(key) == map.end()) {return -1;}
        // Key exists, update ordering list as we are accessing it
        order.erase(map[key].second);   // Remove from list
        order.push_back(key);   // add as most recently used item
        map[key].second = --order.end();    // Update pointer in map to new position of key in order list
        return map[key].first;
    }
    
    void put(int key, int value) {
        // If the key exists, update it and update the position in the order list
        if(map.find(key) != map.end())
        {
            order.erase(map[key].second);   // Remove from the ordering list
        }
        // If we have hit capacity, remove LRU item
        else if(map.size() == capacity)
        {
            map.erase(order.front());   // Remove LRU item from map
            order.pop_front();  // Remove LRU key from ordering list
        }
        // Otherwise, add to LRU cache
        order.push_back(key);   // Add as MRU item to ordering list
        map[key] = {value, --order.end()};  // Add to the map with updated position in ordering list

    }
};
