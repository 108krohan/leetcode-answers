/**

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]

Note:

    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


**/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0;  // the result of a xor b;
        for (auto item : nums) aXorb ^= item;
        // we get the last bit that's different b/w a and b, our two candidate solutions.
        // we do so to partition the data into two buckets with 1 single number and other with duplicates
        // so for example case, with a = 3, b = 5 (let's say)
        // we get aXorB = 6 (110): In next step we extract 
        // the first differing bit, i.e. 1 at middle position
        int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;  // the last bit that a diffs b
        int intA = 0, intB = 0;
        for (auto item : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (item & lastBit) intA = intA ^ item;
            else intB = intB ^ item;
        }
        return vector<int>{intA, intB};   
//         unordered_map<int, int> frequency;
//         vector<int> result;
        
//         for (int i = 0; i < nums.size(); i++) {
//             frequency[nums.at(i)] += 1;
//         }
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (frequency[nums.at(i)] == 1) {
//                 result.push_back(nums.at(i));
//             }
//         }
//         return result;
        // vector<int> result;
        // int xor_val = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     xor_val ^= nums.at(i);
        // }
        // cout << "xor value = " << xor_val;
        // for (int i = 0; i < nums.size(); i++) {
        //     nums.at(i) ^=
        // }
        // cout << "xor 3 = " << (xor_val ^ 3);
        // return result;
    }
};
