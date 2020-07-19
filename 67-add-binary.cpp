/**

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

    Each string consists only of '0' or '1' characters.
    1 <= a.length, b.length <= 10^4
    Each string is either "0" or doesn't contain any leading zero.

**/

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int end_a = a.size() - 1;
        int end_b = b.size() - 1;
        while (end_a >=0 || end_b >= 0) {
            char at_a = (end_a >= 0) ? a.at(end_a) : '0';
            char at_b = (end_b >= 0) ? b.at(end_b) : '0';
            end_a -= 1;
            end_b -= 1;
            
            int sum = (at_a - '0') + (at_b - '0') + carry;
            switch (sum) {
                case 0 : 
                    result += '0';
                    carry = 0;
                    break;
                case 1 : 
                    result += '1';
                    carry = 0;
                    break;
                case 2 : 
                    result += '0';
                    carry = 1;
                    break;
                case 3 : 
                    result += '1';
                    carry = 1;
                    break;
                default : 
                    cout << "coming here! unexpected behaviour." << endl;
                    break;
            }          
        }
        if (carry) {
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
