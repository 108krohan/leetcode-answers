/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/



class Solution {
public:
    void make_result(vector<vector<int>>& total_result, vector<int> result, vector<int>& nums, int index) {
        if(index == nums.size()) {
            total_result.push_back(result);
        }
        if(index < nums.size()) {
            make_result(total_result, result, nums, index + 1);
            result.push_back(nums.at(index));
            make_result(total_result, result, nums, index + 1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result = {};
        vector<vector<int>> total_result;
        make_result(total_result, result, nums, 0);
        return total_result;
    }
};
