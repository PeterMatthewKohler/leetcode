class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Edge case, only 1 task
        if(tasks.size() == 1){return -1;}
        // Hash map to count total # of tasks
        std::unordered_map<int, int> uMap;
        for(const auto& task : tasks){uMap[task]++;}
        // Count rounds needed to do all tasks
        int res = 0;
        for(auto& task : uMap) {
            while(task.second > 0) {
                if(task.second == 1){return -1;}
                else if(task.second == 2){task.second -= 2;}
                else if(task.second == 3){task.second -= 3;}
                else if(task.second == 4){task.second -= 2;}
                else {task.second -= 3;} // 5 or greater
                res++;
            }
        }
        return res;
    }
};
