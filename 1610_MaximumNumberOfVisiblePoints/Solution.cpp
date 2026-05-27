class Solution {
public:

    double PI = 3.14159;
    std::vector<double> calcPolarAngle(const std::vector<std::vector<int>>& points, const std::vector<int>& location)
    {
        // Calculate all points to polar coordinates relative to our location
        std::vector<double> res;
        // Use atan2(x_p - x_0, y_p - y_0)
        for(auto point : points)
        {
            res.push_back((180/PI)*std::atan2(point[1] - location[1], point[0] - location[0]));
        }
        return res;

    }

    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // Points at location are alwasys counted, take the rest and add them to an array
        std::vector<std::vector<int>> angleArr;
        int res = 0; // return result
        int onLoc = 0;
        for(auto point : points)
        {
            if(point[0] == location[0] && point[1] == location[1]){onLoc++;} // Point is on location
            else{angleArr.push_back(point);} // Not on location
        }
        // List of angles to different points
        std::vector<double> angles = calcPolarAngle(angleArr, location);
        // Duplicate the array to deal with transitioning from 360 back to 0
        std::vector<double> copy = angles;
        for(auto ang : angles){copy.push_back(ang + 360);}
        std::sort(copy.begin(), copy.end()); // Sort in increasing order
        // Iterate through the array, incrementing our count if the new angle is less than 'angle' bigger than our L pointer
        // Sliding window to find the maximum number of points we can see as we rotate through the array
        int L = 0;
        for(int R = 0; R < copy.size(); R++)
        {
            if(copy[R] - copy[L] <= angle) // Inside the window
            {
                res = std::max(R - L + 1, res); // Update our answer
            }
            else // Outside the window, shift L until we are back in
            {
                while(copy[R] - copy[L] > angle)
                {
                    L++;
                }
                res = std::max(R - L + 1, res); // Update answer
            }
        }
        return res+onLoc;
    }
};
