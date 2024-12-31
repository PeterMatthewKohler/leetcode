class Solution {
public:
    // Create a map of all courses to their prerequisites
    unordered_map<int, vector<int>> prereqMap; // {Key, Value} = {Course, Prereq List}
    // Hash set to keep track of where we have visited
    // If our path contains a duplicate that means we have a cyclic dependency
    unordered_set<int> path;
    // DFS implementation
    bool dfs(int course)
    {
        // Recursion base case, we have a cyclic dependency
        // If our course has a prereq that we've already visited that is a cyclic dependency
        if(path.count(course))
        {
            return false;   // Cyclic dependency and we can't take the course
        }
        // If this course has no dependency
        if(prereqMap.find(course) == prereqMap.end())
        {
            return true;
        }
        // -- DFS --
        // Mark we've visited this course
        path.insert(course);
        // Traverse the list of prereqs checking for dependencies
        for(int prereq : prereqMap[course])
        {
            if(!dfs(prereq))    // If we have a cyclic dependency
            {
                return false;
            }
        }
        // This path segment is OK, remove it from our path
        path.erase(course);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for(int i = 0; i < numCourses; i++)
        {
            prereqMap[i] = {};
        }
        // Iterate through the list of courses with their prerequisites and build our map
        for(const vector<int>& list : prerequisites)
        {
            prereqMap[list[0]].push_back(list[1]);
        }

        // Iterate through the number of courses and check for a cyclic dependency
        for(int course = 0; course < numCourses; course++)
        {
            if(!dfs(course))
            {
                return false;
            }
        }
        // There are no cyclic dependencies, we can take the course
        return true;
    }
};
