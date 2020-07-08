/**

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> one_result;
        sort(nums.begin(), nums.end());
        map<vector<int>, bool> unique;
        // one guy is placeholder, 
        // the other two are the movers and shakers in response
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1; // first after i
            int k = nums.size() - 1; // last
            int curr_sum;
            while(j < k && k > i) {
                curr_sum = nums.at(i) + nums.at(j) + nums.at(k);
                if(curr_sum == 0) {
                    one_result = {nums.at(i), nums.at(j), nums.at(k)};
                    if(unique.find(one_result)
                      == unique.end()) {
                        // not found case
                        result.push_back(one_result);
                        unique[one_result] = true;                        
                    }
                    j += 1;
                }
                else if (curr_sum > 0) {
                    k -= 1;
                }
                else {
                    j += 1;
                }
            }
        }
        return result;
    }
};
