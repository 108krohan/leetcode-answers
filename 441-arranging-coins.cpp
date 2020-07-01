/*

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.

Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

*/

class Solution {
public:
    int arrangeCoins(int n) {
        int result = 0;
        while((long long int) (result) * (result + 1) / 2 <= n) {
            result += 1;
        }
        return result - 1;
    }
};

/*

Notes for future reader: Solution makes use of simple math formula of sum upto n terms. = n * (n + 1) / 2. 
This division will always be an integer. Why? Because either n, or n + 1 is an integer.
But needs to be long to avoid the unsigned integer value too large runtime exception.
We say result - 1 at last because the last value of result breaks the while loop, 
meaning to say with last value of result (result) * (result + 1) / 2 > n. 
So, that's why solution returns result - 1.
*/
Hence the (long long
