// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Edge case
        if(n == 1)
        {
            return 1;
        }
        // Utilize binary search
        int retVal, left = 1, right = n;
        while(left <= right)
        {
            // Calc midpoint
            int mid = (left + right) / 2;
            // Check it is a bad version
            if(isBadVersion(mid))
            {
                // If it is, we move to the left
                right = mid - 1;
            }
            // If it is not a bad version and the next version is bad, we are done
            else if(!isBadVersion(mid) && isBadVersion(mid+1))
            {
                retVal = mid + 1;
                break;
            }
            // If it is not a bad version and the next version is not bad, we move to the right
            else
            {
                left = mid + 1;
            }
        }
        return retVal;
    }
};
