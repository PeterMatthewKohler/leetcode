class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t retVal = 0;
        for(int i = 0; i < 32; i++)
        {
            // Get the bit value
            int bit = (n >> i) & 1;
            // Add the value shifted to the left
            retVal += bit << (31 - i);
        }
        return retVal;
    }
};
