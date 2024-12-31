class Solution {
public:
    // Iterate through the courses and for each one traverse the adjacency list to see if
    // there is a cyclic dependency

    unordered_map<int, vector<int>> prereqMap;  // Adjacency list
    unordered_set<int> visited; // Track if there is a cyclic dependency
    // Traversal using DFS
    bool dfs(int course)
    {
        // Recursion base case: there is no prerequisite for this course
        if(prereqMap.find(course) == prereqMap.end())
        {
            return true;
        }
        // Recursion base case: we've already checked this course, there is a cyclic dependency
        if(visited.count(course) > 0)
        {
            return false;
        }
        // There is a prereq, we recursively traverse that prereq to see if there is a cyclic dependency
        visited.insert(course); // Mark we are taking this course
        // Traverse the prereqs
        for(auto prereq : prereqMap[course])
        {
            if(!dfs(prereq))
            {
                return false;   // There is a cyclic dependency
            }
        }
        // We've made it through all the prereqs with no issues remove this course from our visited
        // list and then return true
        visited.erase(course);
        // Optimization: remove the prereq from the map to be checked as we've just determined it doesn't have a cyclic dependency
        prereqMap[course].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Edge case: there are no prereqs
        if(prerequisites.size() == 0){return true;} // There are no prereqs so we can safely take the course
        // Init our prereq map
        for(int course = 0; course < numCourses; course++)
        {
            prereqMap[course] = {};
        }
        // Create the adjacency list for all courses
        for(auto prereqList : prerequisites)
        {
            prereqMap[prereqList[0]].push_back(prereqList[1]);
        }
        // Traverse the courses we are taking and check for any cyclic dependencies
        for(int course = 0; course < numCourses; course++)
        {
            if(!dfs(course))
            {
                return false;
            }
        }
        return true;
    }
};
