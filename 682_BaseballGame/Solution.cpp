class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<std::int32_t> record;
        int index = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "+")
            {
                record.push_back(record[index-1]+record[index-2]);
                index++;
            }
            else if(operations[i] == "D")
            {
                record.push_back(record[index-1]*2);
                index++;
            }
            else if(operations[i] == "C")
            {
                record.pop_back();
                index--;
            }
            else
            {
                record.push_back(static_cast<std::int32_t>(stoi(operations[i])));
                index++;
            }
        }
        std::int32_t sum = 0;
        for(auto val : record)
        {
            sum += val;
        }
        return sum;
    }
};
