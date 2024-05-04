class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Create queues for students and sandwiches
        std::queue<int> qstudents;
        std::queue<int> qsandwiches;
        for(int i = 0; i < students.size(); i++)
        {
            qstudents.push(students[i]);
            qsandwiches.push(sandwiches[i]);
        }
        while(!qstudents.empty())
        {
            bool sandwichTaken = false;
            for(int i = 0; i < qstudents.size(); i++)
            {
                if(qstudents.front() == qsandwiches.front())
                {
                    // Student takes the sandwich and leaves
                    qstudents.pop();
                    qsandwiches.pop();
                    sandwichTaken = true;
                    break;
                }
                else if(qstudents.empty())
                {
                    // We are done, so break
                    sandwichTaken = false;
                }
                else
                {
                    // Student doesn't want that one, so moves to back of queue
                    qstudents.push(qstudents.front());
                    qstudents.pop();
                }
            }
            if(!sandwichTaken)
            {
                // Unable to eat, break out of loop
                break;
            }
        }
        return qstudents.size();
    }
};
