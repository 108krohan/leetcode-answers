/**

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

**/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> result(digits.rbegin(), digits.rend());
        int index = 0;
        while(carry && index < result.size()) {
            result.at(index) = result.at(index) + carry;
            if(result.at(index) == 10) {
                result.at(index) = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }
            index += 1;
        }
        if(carry && index == result.size()) {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
