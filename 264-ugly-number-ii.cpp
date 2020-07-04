/**

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.


**/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> results (1,1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) ++i;
            if (results.back() == results[j] * 3) ++j;
            if (results.back() == results[k] * 5) ++k;
        }
        return results.back();
    }
    // below solution times out.
    // bool beautiful(int start) {
    //     while (start % 2 == 0) {
    //         start /= 2;
    //     }
    //     while (start % 3 == 0) {
    //         start /= 3;
    //     }
    //     while (start % 5 == 0) {
    //         start /= 5;
    //     }
    //     if (start == 1) {
    //         return false;
    //     }
    //     return true;
    // }
    // int nthUglyNumber(int n) {
    //     // ugly numbers are numbers with factors as 2, 3, and 5
    //     // this means, multiples of these guys only.
    //     // 1 is considered ugly.
    //     int count = 1;
    //     // assumption: n is a whole number.
    //     if (n <= 1) {
    //         return n;
    //     }
    //     int start = 2;
    //     while (count < n) {  
    //         // increment start until start is an ugly number.
    //         while(beautiful(start)) {
    //             start += 1;
    //         }
    //         start += 1;
    //         count += 1;
    //     }
    //     return start - 1;
    // }
};
