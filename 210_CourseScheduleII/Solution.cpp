class Solution {
public:

    bool dfs(int course, const std::unordered_map<int, std::vector<int>>& courseMap,
             std::unordered_set<int>& cycle, std::unordered_set<int>& visited,
             std::vector<int>& output) {
        // Recursion base cases:
        // 1. We've been to this node before during this traversal -> cycle
        if(cycle.count(course)){return false;}
        // 2. We've already processed this course/node, we can skip this work
        if(visited.count(course)){return true;}

        // Mark we've traversed to this node
        cycle.insert(course);
        // If this node has prereqs, traverse those
        auto it = courseMap.find(course);
        if(it != courseMap.end()) {   // Course has prereqs
            for(const auto& req : it->second) {
                if(!dfs(req, courseMap, cycle, visited, output)){return false;}
            }
        }
        // At this point, course is takeable
        // Mark we've been here
        visited.insert(course);
        // Remove from cycle detection
        cycle.erase(course);
        // Add to output
        output.push_back(course);
        return true;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build a graph w/ all courses and edges from each course to it's prereqs
        std::unordered_map<int, std::vector<int>> courseMap;
        for(const auto& course : prerequisites) {
            courseMap[course[0]].push_back(course[1]);
        }
        // Now traverse the graph using DFS and implementing cycle detection to determine
        // if we've been to a node before during the recursive traversal
        std::unordered_set<int> cycle, visited;
        std::vector<int> output;
        for(int course = 0; course < numCourses; course++){
            if(!dfs(course, courseMap, cycle, visited, output)){return {};}
        }
        return output;
    }
};
