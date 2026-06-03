class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // Sort both arrays first
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        // For each house, find the minimum radius required to reach one of the heaters
        int res = 0;
        for(const auto& house : houses) {
            int minR = INT_MAX;
            for(const auto& heater : heaters) {minR = min(abs(house - heater), minR);}
            res = max(minR, res);
        }
        return res;
    }
};
