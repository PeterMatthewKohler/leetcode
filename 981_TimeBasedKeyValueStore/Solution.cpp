class TimeMap {
public:
    std::unordered_map<std::string, std::map<int, std::string>> uMap_;

    TimeMap() {
        // Single map, key/value pair is <string, std::map<int, string>>
    }
    
    void set(string key, string value, int timestamp) {
        if(uMap_.find(key) == uMap_.end()) {
            std::map<int, std::string> m = {{timestamp, value}};
            uMap_[key] = m;
        }
        else {
            // Overwrite
            if(uMap_[key].find(timestamp) != uMap_[key].end()) {
                uMap_[key].erase(timestamp);
            }
            uMap_[key][timestamp] = value;
        }
    }
    
    string get(string key, int timestamp) {
        // Check if key exists
        if (uMap_.find(key) == uMap_.end()) {return "";}
        // If key exists grab the inner map
        auto& m = uMap_[key];
        // Return iterator to key whose value is strictly greater than timestamp
        auto it = m.upper_bound(timestamp);
        // If map is empty
        if (it == m.begin()) {return "";}
        // Step back one entry to get most recent before timestamp
        // if timestamp doesn't exist
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
