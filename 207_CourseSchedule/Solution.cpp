class Solution {
public:
    bool dfs(int course, const std::unordered_map<int, std::vector<int>>& courseMap,
             std::unordered_set<int>& cycle, std::unordered_set<int>& visited) {
        // Recursion base cases:
        // 1. We've already been here and are in a cycle
        if(cycle.count(course)){return false;}
        // 2. We've already checked this course, i.e. visited
        if(visited.count(course)){return true;}

        // Add this course to the cycle tracker
        cycle.insert(course);
        // Now do DFS recursion to check the prereqs if they exist
        auto it = courseMap.find(course);
        if(it != courseMap.end()) {
            for(const auto& prereq : it->second) {
                if(!dfs(prereq, courseMap, cycle, visited)){return false;}
            }
        }
        visited.insert(course);
        cycle.erase(course);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Make graph with nodes and prereqs as vertices
        std::unordered_map<int, std::vector<int>> courseMap;    // <course, prereq list>
        // Build out graph
        for(const auto& course : prerequisites) {courseMap[course[0]].push_back(course[1]);}
        // Track courses we've already traversed?
        std::unordered_set<int> visited;
        // Track if we are in a cycle
        std::unordered_set<int> cycle;
        // Now just go through all courses, running DFS call on each one
        for(int course = 0; course < numCourses; course++) {
            if(!dfs(course, courseMap, cycle, visited)){return false;}
        }
        return true;
    }
};
