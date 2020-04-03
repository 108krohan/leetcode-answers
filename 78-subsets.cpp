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

class Solution {
public:
    
    void getSubsets(vector<vector<int>> &result, 
                    vector<int> &nums,
                    vector<int> currentResult, int index) {
        if(index == nums.size()) {
            result.push_back(currentResult);
            return;
        }
        getSubsets(result, nums, currentResult, index + 1);
        currentResult.push_back(nums.at(index)); 
        getSubsets(result, nums, currentResult, index + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> currentResult;
        getSubsets(result, nums, currentResult, 0);
        return result;
    }
};
