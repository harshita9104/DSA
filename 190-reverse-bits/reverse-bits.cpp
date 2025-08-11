class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
//         Start with an output value initialized to 0.
// For each bit position ( i ) in the 32-bit number:
// Extract the ( i )-th bit of ( n ) using a bitwise AND with a mask (n & 1).
// Append this bit to the reversed position in the output by left-shifting the output and adding the extracted bit.
// Right-shift ( n ) by 1 to process the next bit.
// Repeat this for all 32 bits.
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;       // Extract the least significant bit
            result = (result << 1) | bit; // Append the bit to the result
            n = n >> 1;           // Right-shift n to process the next bit
        }
        return result;
    }
};