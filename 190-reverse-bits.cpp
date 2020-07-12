/*

Reverse bits of a given 32 bits unsigned integer.

 

Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:

Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

 

Note:

    Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.

 

Follow up:

If this function is called many times, how would you optimize it?


*/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse;
        for(int i = 0; i < 32; i++) {
            uint32_t shift_n = n >> i;
            uint32_t value_i = 1 & shift_n;
            reverse <<= 1;
            reverse += value_i;
        }
        return reverse;
    }
    // doesn't work for: 11111111111111111111111111111101
    // the strategy doesn't work like this
    // the strategy being: move to ith place
    // the winning strategy instead
    // is to bring them to the first position 
    // via bit shifts
    // cout << "position = " << position_i_1 << endl;
    // uint32_t value_i = n & position_i_1;
    // value_i >>= i;
    // cout << "value = " << value_i << endl;
};
