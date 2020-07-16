/**

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]



**/

class Solution {
public:
    double myPow(double x, int n) {
        double result = x; 
        if (n == 0) {
            return 1;
        }
        if (x == 1) {
            return 1;
        }
        bool isNegative = false;
        long long int false_n = n;
        if(n < 0) {
            isNegative = true;
            false_n = n;
            false_n = -false_n;
        }
        double sideways = 1;
        while (false_n > 1) {
            if (false_n % 2) {
                sideways *= result;           
            }
            result *= result;
            // cout << "n = " << n << endl;
            // cout << "result = " << result << endl;
            // cout << "sideways = " << sideways << endl;
            false_n /= 2;
        }
        result = result * sideways;
        if (isNegative) {
            result = 1 / result;
        }
        return result;
        // below solution doesn't work..
        // if(n == 0) 
        //     return 1;
        // if(x == 1) {
        //     return 1;
        // }
        // bool isNegative = (n < 0) ? true: false;
        // if(isNegative) {
        //     n = -n;
        // }
        // double result = x;
        // for(int i = 1; i < n; i++) {
        //     result = result * x;
        // }
        // if(isNegative) {
        //     result = 1/result;
        // }
        // return result;
    }
};
