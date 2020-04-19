/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int low = 0; 
        int high = nums.size() - 1; 
        int mid;
        while(low < high) {
            mid = (low + high) / 2;
            if(nums.at(mid) == target) {
                return mid;
            }
            // has to be `<=` and not `<` 
            // for when mid = low.
            if(nums.at(low) <= nums.at(mid)) {
                // shuruat ascends
                if(nums.at(low) <= target && target < nums.at(mid)) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                // second-half ascends
                if(nums.at(mid) < target && target <= nums.at(high)) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return nums.at(low) == target ? low : -1;
    }
};
