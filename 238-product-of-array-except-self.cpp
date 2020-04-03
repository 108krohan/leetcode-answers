Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        result.push_back(1);
        // Left se
        for(int l = 0; l < nums.size() - 1; l++) {
            result.push_back(nums[l] * result[l]);
        }
        
        // Right se
        int R = 1;
        for(int r = nums.size() - 1; r >= 1; r--) {
            
            R *= nums.at(r);
            result.at(r - 1) *= R;
        }
        return result;
        
    }
};
